# api로만 접근할 수 있는 경우에는 크롤링 함수가 작동하지 않는다.
# 이런 경우를 대비하기 위해 크롤링 함수를 2개로 나눴다.
# 1. 페이지를 스크립하는 스크립_페이지 함수
# 2. 스파이더링 기법이 담긴 겟_링크 함수.

import requests
from bs4 import BeautifulSoup
from urllib.robotparser import RobotFileParser
from urllib.parse import urljoin
from time import sleep

def check_can_fetch(url, user_agent):
    rp = RobotFileParser()
    rp.set_url(url + "/robots.txt")
    rp.read()
    return rp.can_fetch(user_agent, url)

def scrape_page(url, user_agent):                           # 웹페이지를 스크립핑하는 함수
    if check_can_fetch(url, user_agent):
        response = requests.get(url)
        soup = BeautifulSoup(response.text, 'html.parser')
        titles = soup.find_all(True, class_='title')
        for title in titles:
            print(title.text)
    else:
        print(f"해당 웹페이지에 대한 접근을 허가 받지 못함: {url}")

def get_links(url, user_agent):                             # 스파이더링 기법이 담긴 함수
    if check_can_fetch(url, user_agent):
        response = requests.get(url)
        soup = BeautifulSoup(response.text, 'html.parser')
        links = [urljoin(url, a['href']) for a in soup.find_all('a', href=True)]
        return links
    else:
        print(f"해당 웹페이지에 대한 접근을 허가 받지 못함: {url}")
        return []


user_agent = 'python_student0001'
start_url = 'https://opentutorials.org/course/1'
urls_for_crawling = [start_url]
crawled_urls = set()

a = 10
while a:
    url = urls_for_crawling.pop(0)
    if url not in crawled_urls:
        print(f"크롤링 중인 페이지: {url}")
        scrape_page(url, user_agent)
        links = get_links(url, user_agent)
        urls_for_crawling.extend(links)
        crawled_urls.add(url)
        sleep(1)  # 서버에 부담을 주지 않기 위해 대기시간 설정
        a -= 1


# 개선점 1. 너무 느리니까 병렬로 크롤링할 필요가 있다
# 개선점 2. 수집한 데이터를 db에 넣을 필요가 있다.

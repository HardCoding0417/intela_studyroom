# sleep을 사용하여 서버에 부하를 주지 않도록 업그레이드했다

import requests
from bs4 import BeautifulSoup
from urllib.robotparser import RobotFileParser
from urllib.parse import urljoin
from time import sleep                              # 크롤링 속도를 늦춰주기 위한 sleep을 불러온다

def check_can_fetch(url, user_agent):
    rp = RobotFileParser()
    rp.set_url(url + "/robots.txt")
    rp.read()
    return rp.can_fetch(user_agent, url)

def crawling(url, user_agent):
    if check_can_fetch(url, user_agent):
        response = requests.get(url)
        soup = BeautifulSoup(response.text, 'html.parser')
        titles = soup.find_all(True, class_='title')
        for title in titles:
            print(title.text)
        links = [urljoin(url, a['href']) for a in soup.find_all('a', href=True)]
        return links
    else:
        print(f"허용되지 않음: {url}")
        return []

user_agent = 'python_student0001'
start_url = 'https://ko.wikipedia.org/wiki'
urls_to_crawling = [start_url]
crawled_urls = set()


a=10
while a:
    url = urls_to_crawling.pop(0)
    if url not in crawled_urls:
        new_links = crawling(url, user_agent)
        urls_to_crawling.extend(new_links)
        sleep(1)                                # 1초 슬립
        a -= 1



# 개선점 1. 너무 느리니까 병렬로 크롤링할 필요가 있다
# 개선점 2. 수집한 데이터를 db에 넣을 필요가 있다.

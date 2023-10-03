# SSL 인증이 없는 사이트도 크롤링하는 프로그램이다.

import requests
from bs4 import BeautifulSoup
from urllib.robotparser import RobotFileParser
from urllib.parse import urljoin

def check_can_fetch(url, user_agent):               # 착한 크롤러 함수
    rp = RobotFileParser()
    rp.set_url(url + "/robots.txt")
    rp.read()
    return rp.can_fetch(user_agent, url)

def crawling(url, user_agent):                      # 크롤링 함수
    if check_can_fetch(url, user_agent):
        response = requests.get(url, verify=False)  # SSL 인증문제를 해결하기 위해 verify=False를 사용했다.
                                                    #   SSL이란 데이터 전송 프로토콜이다.
                                                    #   사이트들은 SSl 인증서를 받아 자신이 신뢰할 수 있는 사이트임을 증명하는데
                                                    #   이 인증서는 CA(Certificate Authority)로부터 발급되며,
                                                    #   브라우저들이 해당 사이트가 안전한 곳인지를 판단하는 근거가 된다


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


a=10 # 10번만 반복하도록 임시로 정함.
while a:            # 반복문을 while로 바꿈
    url = urls_to_crawling.pop(0)  # url리스트의 첫 번째 url을 찾아간다.
    if url not in crawled_urls:    # 해당 url이 크롤링되지 않은 주소인지 체크하고, 맞다면 아래 블록들을 실행한다.
        new_links = crawling(url, user_agent)   # 크롤링 함수로 해당 url을 크롤링한다. (목표 데이터인 titel과 크롤링을 이어나가기 위한 링크들을 수집함)
        urls_to_crawling.extend(new_links)      # 새로운 링크를 리스트에 추가한다.
        crawled_urls.add(url)                   # 해당 url을 크롤링한 것으로 표시한다.
        a -= 1


# 개선점 1. 서버에 부하를 주지 않도록 크롤링 속도를 줄일 필요가 있다.
# 개선점 2. 그럼 너무 느리니까 병렬로 크롤링할 필요가 있다
# 개선점 3. 수집한 데이터를 db에 넣을 필요가 있다.

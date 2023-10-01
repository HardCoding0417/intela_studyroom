import requests
from bs4 import BeautifulSoup
from urllib.robotparser import RobotFileParser
from urllib.parse import urljoin

def check_can_fetch(url, user_agent):               # 착한 크롤러 함수
    rp = RobotFileParser()
    rp.set_url(url + "/robots.txt")
    rp.read()
    return rp.can_fetch(user_agent, url)

def crawling(url, user_agent):                      # 프로그램이 알아서 여기저기 돌아다니도록 해주는 크롤링 함수
    if check_can_fetch(url, user_agent):            # 크롤링할 수 있는 곳인지 체크하고 True가 반환되면 아래의 블록들을 실행한다
        response = requests.get(url)
        soup = BeautifulSoup(response.text, 'html.parser')
        titles = soup.find_all(True, class_='title')
        for title in titles:
            print(title.text)
        links = [urljoin(url, a['href']) for a in soup.find_all('a', href=True)] # urljoin을 사용하여 상대링크를 절대링크로 바꿈.
        return links
    else:
        print(f"허용되지 않음: {url}")
        return []

user_agent = 'python_student0001'
start_url = 'https://ko.wikipedia.org/wiki'    # 시작 링크
urls_to_crawling = [start_url]          # 시작 링크에서 수집한 링크들이 담길 변수
crawled_urls = set()                    # 이미 크롤링한 url들을 set형 군집데이터로 저장한다.


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

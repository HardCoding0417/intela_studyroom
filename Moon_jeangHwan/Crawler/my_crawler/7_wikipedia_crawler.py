import requests
from bs4 import BeautifulSoup
from urllib.robotparser import RobotFileParser
from urllib.parse import urljoin
from time import sleep

# 먼저, 위키피디아 pip을 설치한다
# pip install wikipedia-api

import wikipediaapi

# 그런 뒤, wikipedia-api 모듈을 import한다.

def check_can_fetch(url, user_agent):                       # robots.txt를 준수하기 위한 함수
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

def get_links2(page, crawled_urls):                         # 위키피디아용 스파이더링 함수
    new_links = []
    links = page.links
    for title in links.keys():
        if title not in crawled_urls:
            new_links.append(title)
    return new_links

user_agent = 'python_student0001'

urls_to_crawling = ['파이썬']  # 시작 페이지
crawled_urls = set()

wiki = wikipediaapi.Wikipedia(user_agent, language='ko', extract_format=wikipediaapi.ExtractFormat.WIKI) 
    # wikipedia 클래스를 사용했다.
    # 한국 위키만 접속하도록 했고,
    # 텍스트만이 아니라 모든 데이터, 즉... 위키 원본을 읽도록 지시했다.

a=10
while a:
    page_title = urls_to_crawling.pop(0)  # 위키피디아에서 검색할 문자열을 가져옴 이 경우는 '파이썬'
    page = wiki.page(page_title)          # 가져온 문자열로 찾아낸 페이지를 page 변수에 담음
    if page.exists() and page_title not in crawled_urls:  # 페이지가 존재하고 아직 크롤링하지 않았으면

        print('페이지 제목: ', page.title)      # 페이지 제목 출력
        print('페이지 내용: ', page.text[:60])  # 페이지 내용 일부 출력
        print()                                # \n 대신 넣음

        new_links = get_links2(page, crawled_urls)  # 스파이더링
        urls_to_crawling.extend(new_links)

        crawled_urls.add(page_title)                # 중복 탐색 방지
        sleep(0.3)

        a -= 1


# 개선점 1. sleep의 한계를 극복하려면 병렬로 크롤링할 필요가 있다
# 개선점 2. 수집한 데이터를 db에 넣을 필요가 있다.

# 아이디어 1. ai를 통해 웹 사이트의 변경 시점, 변경 빈도 등을 학습시킨다면 편할 것 같다


#----------------------------
# https://velog.io/@lybin10/%EB%84%A4%EC%9D%B4%EB%B2%84-API%EB%A5%BC-%EC%9D%B4%EC%9A%A9%ED%95%9C-%ED%81%AC%EB%A1%A4%EB%A7%81
# 네이버 api를 이용한 크롤링
# -------------
# 1. 크롤지연   : 웹 사이트들은 크롤링 속도를 늦추는, '크롤 지연'이란 규칙을 갖고 있다. 위키피디아의 크롤링 속도가 느린 건 이거 때문.
# 2. 데이터 덤프: 웹사이트들이 배포하는 것으로, 해당 사이트의 전체 데이터 혹은 일부 데이터를 파일 형태로 저장한 것.
#                CSV, JSON, SQL, XML 등의 형식으로 제공되며 해당 웹사이트의 데이터베이스 구조가 반영되어있다
#-----------------
# Wikipedia-API 모듈은 위키피디아의 MediaWiki API을 파이썬화 시킨 것이다.
# 주요 클래스로는 Wikipedia와 WikipediaPage가 있다.

# Wikipedia의 주요 메서드는 아래의 3개다.
# page(title): 주어진 제목의 WikipediaPage를 반환한다.
#   page_py = wiki.page('파이썬') 이런 식으로 사용하며, 파이썬 페이지가 존재하면 해당 페이지를 반환한다. (내부의 내용을 다루는 건 WikipediaPage클래스로 한다)
# exists(page): 인자로 받은 WikipediaPage가 실제로 존재하는지 확인한다
# summary(page, chars): 인자로 받은 WikipediaPage의 요약문을 반환한다 chars 파라미터에 인자를 넣으면 반환되는 문자의 수를 제한할 수 있다




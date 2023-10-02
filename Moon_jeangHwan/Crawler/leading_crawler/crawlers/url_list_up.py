import requests
from bs4 import BeautifulSoup
from urllib.parse import urljoin
from crawler import check_can_fetch
import json

MAX_LINKS_PER_PAGE = 10

visited_urls = set()  # 방문한 URL 저장
static_crawling_possible = []  # 정적 크롤링 가능한 URL 저장
static_crawling_impossible = []  # 정적 크롤링 불가능한 URL 저장

def spidering(url, user_agent, new_links):

    # 방문한 적이 있는 주소면 스킵하고, 방문한 적이 없으면 방문한 곳 목록에 추가
    if url in visited_urls:
        return
    visited_urls.add(url)
    
    # robots.txt 체크
    if not check_can_fetch(url, user_agent):    
        static_crawling_impossible.append(url)
        return

    # 정적 크롤링 가능, 불가능으로 분류
    response = requests.get(url)
    if response.status_code != 200:
        static_crawling_impossible.append(url)
        return
    static_crawling_possible.append(url)

    # 페이지 내의 링크 10개를 찾아서 크롤링 예정 리스트에 올림
    soup = BeautifulSoup(response.text, 'html.parser')
    for a_tag in soup.find_all('a', href=True)[:MAX_LINKS_PER_PAGE]: # 최대 10개의 링크만 얻음
        new_url = urljoin(url, a_tag['href'])
        if new_url not in visited_urls:
            new_links.append(new_url) # 새로 발견한 링크 저장

with open("config.json", "r") as file:
    config = json.load(file)

all_urls = []
for urls in config["categories"].values():
    all_urls.extend(urls)

user_agent = config["fresi"]

new_links = []

for url in urls:
    spidering(url, user_agent, new_links)

while new_links: # new_links에 아직 크롤링하지 않은 링크가 있다면
    url = new_links.pop(0) # 링크를 하나 가져온 후
    spidering(url, user_agent, new_links) # 해당 링크에 대해 크롤링


print("정적 크롤링 가능한 URL들:")
for url in static_crawling_possible:
    print(url)

print("\n정적 크롤링 불가능한 URL들:")
for url in static_crawling_impossible:
    print(url)







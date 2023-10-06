import requests
from bs4 import BeautifulSoup
from urllib.parse import urljoin
from time import sleep
import json
import logging
from Moon_jeangHwan.Crawler.leading_crawler.crawlers.mvp_crawler import check_can_fetch
from datetime import datetime, timedelta

MAX_LINKS_PER_PAGE = 10

visited_urls = set()  # 방문한 URL 저장
static_crawling_possible = []  # 정적 크롤링 가능한 URL 저장
static_crawling_impossible = []  # 정적 크롤링 불가능한 URL 저장

# 로깅
logging.basicConfig(level=logging.INFO,
                format='%(asctime)s - %(levelname)s - %(message)s',
                filename="crawler.log")

def spidering(url, user_agent, new_links):
    try:
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

        # 페이지 내의 링크를 10개 찾아서 크롤링 예정 리스트에 올림
        soup = BeautifulSoup(response.text, 'html.parser')
        for a_tag in soup.find_all('a', href=True)[:MAX_LINKS_PER_PAGE]:  # 최대 10개의 링크만 얻음
            new_url = urljoin(url, a_tag['href'])
            if new_url not in visited_urls:
                new_links.append(new_url)  # 새로 발견한 링크 저장

    # 예외상황 발생 시
    except Exception as e:
        logging.error(f"Error while processing {url}. Reason: {e}")


# 크롤링 돌릴 준비
with open("../config/config.json", "r", encoding="utf-8") as file:
    config = json.load(file)
all_urls = []
for urls in config["categories"].values():
    all_urls.extend(urls)
user_agent = config["user_agent"]

# 크롤링 실시
new_links = []
for url in all_urls:
    spidering(url, user_agent, new_links)

# 스파이더링 준비
start_time = datetime.now()
crawl_duration = timedelta(minutes=10)

# 스파이더링 실시
while new_links and datetime.now() - start_time < crawl_duration:
    url = new_links.pop(0)
    spidering(url, user_agent, new_links)

print("정적 크롤링 가능한 URL들:")
for url in static_crawling_possible:
    print(url)

print("\n정적 크롤링 불가능한 URL들:")
for url in static_crawling_impossible:
    print(url)



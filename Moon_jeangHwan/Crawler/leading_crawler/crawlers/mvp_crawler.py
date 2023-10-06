import requests
from urllib.robotparser import RobotFileParser
from bs4 import BeautifulSoup
import logging

# 로깅 설정
logging.basicConfig(level=logging.INFO,
                    format='%(asctime)s - %(levelname)s - %(message)s',
                    filename="crawler.log")


# robots.txt를 준수하기 위한 함수
def check_can_fetch(url, user_agent):
    rp = RobotFileParser()
    rp.set_url(url + "/robots.txt")
    rp.read()
    return rp.can_fetch(user_agent, url)


# 접근 (성공 시 페이지를 요청)
def fetch_page(url, user_agent):
    if not check_can_fetch(url, user_agent):
        logging.warning(f"해당 웹페이지에 대한 접근을 허가 받지 못함: {url}")
        return None
    response = requests.get(url)
    return response

soup = BeautifulSoup(fetch_page("https://www.mk.co.kr/news/business/latest", "user_agent").content, "html.parser")
news_list = soup.select("ul.news_list.latest_news_list > li.news_node")

results = []
for news in news_list:
    title_element = news.select_one("h3.news_ttl")
    summary_element = news.select_one("p.news_desc")  # 이 예제에서는 HTML에 summary가 없으므로 None을 반환합니다.
    link_element = news.select_one("a.news_item")
    # 만약 title_element가 없거나 빈 문자열이면, 다음 news element로 넘어간다.
    if not title_element or not title_element.text.strip():
        continue

    title = title_element.text.strip()  # 제목
    link = link_element['href']  # 링크

    # 요약 정보는 위의 HTML에서 제공되지 않으므로 이 부분은 생략하거나 다른 방법으로 처리해야 합니다.
    results.append({
        'title': title,
        'link': link
    })
# 결과를 출력합니다.
for item in results:
    print("제목:", item['title'])
#    print("요약:", item['summary'])
    print("링크:", item['link'])
    print("-" * 50)
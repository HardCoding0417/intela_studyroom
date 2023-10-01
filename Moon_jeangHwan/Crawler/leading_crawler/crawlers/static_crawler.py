import requests
from bs4 import BeautifulSoup
from urllib.parse import urljoin
from common_crawler_utils import check_can_fetch

def parse_page(url, user_agent): # 파싱
    if not check_can_fetch(url, user_agent):
        print(f"해당 웹페이지에 대한 접근을 허가 받지 못함: {url}")
        return None

    response = requests.get(url)
    soup = BeautifulSoup(response.text, 'html.parser')
    return soup

def scrape_page(url, user_agent):   # 정적 스크래핑
    soup = parse_page(url, user_agent)
    if soup:
        titles = soup.find_all(True, class_='title')
        for title in titles:
            print(title.text)

def Spidering(url, user_agent):     # 정적 스파이더링
    soup = parse_page(url, user_agent)
    if soup:
        return [urljoin(url, a['href']) for a in soup.find_all('a', href=True)]
    else:
        return []

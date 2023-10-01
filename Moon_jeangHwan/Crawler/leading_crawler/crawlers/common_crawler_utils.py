import requests
from urllib.robotparser import RobotFileParser
from bs4 import BeautifulSoup
import logging

# 로깅 설정
logging.basicConfig(level=logging.INFO, 
                    format='%(asctime)s - %(levelname)s - %(message)s', 
                    filename="crawler.log")


# 접근 시도
def fetch_page(url, user_agent):
    if not check_can_fetch(url, user_agent):
        logging.warning(f"해당 웹페이지에 대한 접근을 허가 받지 못함: {url}")
        return None
    response = requests.get(url)
    return response

# robots.txt를 준수하기 위한 함수
def check_can_fetch(url, user_agent):   
    rp = RobotFileParser()
    rp.set_url(url + "/robots.txt")
    rp.read()
    return rp.can_fetch(user_agent, url)

# 파싱
def parse_page(url, user_agent): 
    response = requests.get(url)
    soup = BeautifulSoup(response.text, 'html.parser')
    return soup


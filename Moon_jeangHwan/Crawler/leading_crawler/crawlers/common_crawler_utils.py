import requests
from urllib.robotparser import RobotFileParser
from bs4 import BeautifulSoup

def check_can_fetch(url, user_agent):   # robots.txt를 준수하기 위한 함수
    rp = RobotFileParser()
    rp.set_url(url + "/robots.txt")
    rp.read()
    return rp.can_fetch(user_agent, url)

def parse_page(url, user_agent): # 파싱
    if not check_can_fetch(url, user_agent):
        print(f"해당 웹페이지에 대한 접근을 허가 받지 못함: {url}")
        return None

    response = requests.get(url)
    soup = BeautifulSoup(response.text, 'html.parser')
    return soup


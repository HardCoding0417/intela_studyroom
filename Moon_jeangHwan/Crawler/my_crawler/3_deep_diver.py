import requests
from bs4 import BeautifulSoup
from urllib.robotparser import RobotFileParser
from urllib.parse import urljoin                    # url라이브러리 내의 urllib.parse모듈에서 url조인 함수를 불러온다. 
                                                    # urljoin 함수는 상대 url을 절대 url로 바꿔주는 기능을 갖고 있ㄷ
                                                    # 상대주소: \\폴더 --- 절대주소: c\폴더\폴더\폴더\폴더

def check_can_fetch(url, user_agent):               # 착한 크롤러로 만들어주는 함수
    rp = RobotFileParser()
    rp.set_url(url + "/robots.txt")
    rp.read()
    return rp.can_fetch(user_agent, url)

def crawling(url, user_agent):                      # 프로그램이 알아서 여기저기 돌아다니도록 해주는 함수
    if check_can_fetch(url, user_agent):            # 크롤링할 수 있는 곳인지 체크. True면 아래 블록들을 실행.
        response = requests.get(url)
        soup = BeautifulSoup(response.text, 'html.parser')
        titles = soup.find_all(True, class_='title')
        for title in titles:
            print(title.text)
        links = [a['href'] for a in soup.find_all('a', href=True)]  # find_all + 반복문으로 페이지 내의 링크들을 찾아서 links 변수에 저장. links를 반환
        return links
    else:
        print(f"허용되지 않음: {url}")
        return []
        links = [urljoin(url, a['href']) for a in soup.find_all('a', href=True)] # 위의 links 변수 제작 코드의 변형. 
                                                                                 # urljoin을 사용하여 상대링크를 절대링크로 바꾸고 있다.
        return links

user_agent = 'python_student0001'
start_url = 'https://www.naver.com/'    # 시작 링크
urls_to_crawling = [start_url]          # 시작 링크에서 수집한 링크들이 담길 변수

for url in urls_to_crawling:
    new_links = crawling(url, user_agent)   # 시작 페이지에서 채집한 링크들을 new_links에 넣음
    urls_to_crawling.extend(new_links)      # extend메서드를 사용해 new_links 리스트를 urls_to_crawling 리스트의 끄트머리에 이어붙인다.
    
                                                # extend는 파이썬의 메서드로, 리스트의 끝에 다른 리스트를 추가하는 기능을 갖고 있음.
                                                # 예시) [1,2,3]와 [4,5]를 extend하면 [1,2,3,4,5]가 됨

# 이 url 타기 기법은 브레드크럼, 또는 스파이더링 기법이라고 불린다.


# 개선점 1. url만 수집하는 게 아니라 크로울링도 병행하도록 수정해야 함




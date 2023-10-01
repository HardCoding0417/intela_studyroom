# 이 프로그램은 urllib.robotparser 모듈을 사용하여
# robots.txt 파일을 파싱 후 읽어보고, 특정 URL이 내게 허용되었는지를 확인한 뒤
# 자신에게 허용된 곳일 때만 크롤링한다.

# 즉, robots.txt를 준수하는 '착한 버전의 크롤러'라고 할 수 있겠다


import requests
from bs4 import BeautifulSoup
from urllib.robotparser import RobotFileParser      # urllib.robotparser 모듈을 추가했다. (url라이브러리 로봇 파서)


def check_can_fetch(url, user_agent):
    # robots.txt를 확인하여 크롤링해도 되는지 확인해주는 함수.
    rp = RobotFileParser()                # 1단계. 인스턴스 rp를 생성한다.
    rp.set_url(url + "/robots.txt")       # 2단계. set_url 메서드를 사용하여 rp가 분석할 robots.txt 파일의 위치를 세팅한다.
                                          #        robots.txt는 항상 루트 페이지에 있으므로 인자로 받은 url에 /robots.txt만 추가해주면
                                          #        rp 인스턴스 내에 해당 robots.txt의 위치가 등록(set)된다
    rp.read()                             # 3단계. set_url이 잡아준 위치의 robots.txt를 읽는다.
    return rp.can_fetch(user_agent, url)    # 4단계. user_agent(나)가 URL에 접근할 수 있는지를 확인하고 가능하면 True를 반환한다.
                                            #   RobotFileParser()클래스의 내장 메서드. can_fetch는 
                                            #   매개변수로 전달받은 user_agent(나)가 해당 url을 크롤링할 수 있는지를,
                                            #   robots.txt 파일에 기록된 규칙에 따라 체크하고 가능하면 True, 불가능하면 False를 반환한다.

url = 'https://www.naver.com/'
user_agent = 'python_student0001'           # 크롤링하는 봇의 이름임. 아무 의미 없음.

if check_can_fetch(url, user_agent):        # 함수를 사용하여 크롤링해도 되는 페이지인지 체크. True면 아래 블록들을 실행한다
    response = requests.get(url)
    soup = BeautifulSoup(response.text, 'html.parser')

    titles = soup.find_all(True, class_='title')

    for title in titles:
        print(title.text)
else:
    print("허용되지 않음")


    

# 네이버는 대부분의 크롤링이 막혀있다

# 개선사항
# 1. 깊게 파고들도록 (심도에 제한 걸어야 함)
# 2. 이미 본 페이지는 다시 보지 않도록.
# 3. 




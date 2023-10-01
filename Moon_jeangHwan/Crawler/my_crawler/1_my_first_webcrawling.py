import requests
from bs4 import BeautifulSoup

# 1단계. 해당 페이지의 정보를 받아온다
# 2단계. 원하는 정보를 추출한다 (이를 파싱parsing이라고 한다.)


                                    # 1단계. 해당 페이지의 정보를 받아온다

url = 'https://opentutorials.org/course/1'      # 크롤링하려는 웹페이지의 주소를 변수에 저장
response = requests.get(url)        # 해당 페이지의 정보를 request모듈의 get()로 받아옴

soup = BeautifulSoup(response.text, 'html.parser') # 2단계. 원하는 정보를 파싱parsing한다 (parsing == 복잡한 데이터를 이해하기 쉬운 형태로 이해하는 것)
                                                   # 여기서는 HTML 소스 코드를 분석하여 웹 페이지의 구조를 이해하는 것을 파싱이라 부르고 있다.
                                                   # html소스란 걸 알고있지 못하면 단순히 <와 >가 많이 들어있는 txt에 불과하니까
                                                   # 파싱을 해야 html소스임을 인지시키는 것이다

                                                   # 어떻게 파싱할 것인가?
                                                   # bs4모듈의 BeautifulSoup클래스를 사용하여 파싱할 것이다.
                                                   # 이 클래스는 웹페이지의 HTML 코드를 파싱하여 파이썬에서 쉽게 다룰 수 있는 파싱 트리로 변환해주는 역할을 한다.
                                                   # BeautifulSoup(markup, feature)     # markup: 분석하려는 문자열 또는 파일. features: 사용할 파서의 이름

                                                   # 분석하려는 문자열은 response.txt고
                                                   # html페이지니까 html파서를 이용한다.

titles = soup.find_all(True, class_='title')    # 3단계. 원하는 요소를 추출한다
                                                # class가 'title'인 요소를 모두 찾는다. 
                                                # 앞의 인자를 True가 아니라 h2 같은 걸로 하면 h2 중에서만 찾는다.

for title in titles:
    print(title.text) # 제목 텍스트 출력



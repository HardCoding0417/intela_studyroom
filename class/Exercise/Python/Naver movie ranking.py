import requests
from bs4 import BeautifulSoup

import datetime


response = requests.get("https://movie.daum.net/ranking/reservation")
html = response.text

soup = BeautifulSoup(html, 'html.parser')
date = datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")

print(f"<다음 영화 순위 - {date}>\n")
i = 1
for tag in soup.find('ol', {'class': 'list_movieranking'}).find_all('a', {'class': 'link_txt'}):
    print(f"{i}. {tag.get_text()}")
    i += 1
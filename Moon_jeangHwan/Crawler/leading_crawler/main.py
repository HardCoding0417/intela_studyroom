import json
from common_crawler_utils import check_can_fetch

with open("config.json", "r") as file:
    config = json.load(file)    # 밑에서 config["user_agent"] 형태로 사용된다

user_agent = config["user_agent"]
news_urls = config["news_urls"]

for url in news_urls:
    can_fetch = check_can_fetch(url, user_agent)
    if can_fetch:
        print(f"접근 가능: {url}")
    else:
        print(f"접근 불가능: {url}")
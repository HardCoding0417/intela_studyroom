import wikipediaapi
import json

# 설정 파일 로드
with open("config.json", "r") as file:
    config = json.load(file)    # 밑에서 config["user_agent"] 형태로 사용된다

wiki = wikipediaapi.Wikipedia(config["user_agent"], language='ko', extract_format=wikipediaapi.ExtractFormat.WIKI) 
    # 한국 위키만 접속하도록 했다.
            
def wiki_spidering(page, crawled_urls):                         # 위키피디아용 API 스파이더링 함수
    new_links = []
    links = page.links
    for title in links.keys():
        if title not in crawled_urls:
            new_links.append(title)
    return new_links



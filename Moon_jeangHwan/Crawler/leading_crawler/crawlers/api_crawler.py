import wikipediaapi

user_agent = 'python_student0001'

wiki = wikipediaapi.Wikipedia(user_agent, language='ko', extract_format=wikipediaapi.ExtractFormat.WIKI) 
    # wikipedia 클래스를 사용했다.
    # 한국 위키만 접속하도록 했고,
    # 텍스트만이 아니라 모든 데이터, 즉... 위키 원본을 읽도록 지시했다. 
            
def get_links2(page, crawled_urls):                         # 위키피디아용 API 스파이더링 함수
    new_links = []
    links = page.links
    for title in links.keys():
        if title not in crawled_urls:
            new_links.append(title)
    return new_links



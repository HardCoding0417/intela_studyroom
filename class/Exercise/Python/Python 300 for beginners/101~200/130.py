import requests
btc = requests.get("https://api.bithumb.com/public/ticker/").json()['data']

print("상승장" if int(btc['opening_price']) - int(btc['min_price']) > 0 else "하락장")
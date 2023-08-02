ohlc = [
    ["open", "high", "low", "close"],
    [100, 110, 70, 100],
    [200, 210, 180, 190],
    [300, 310, 300, 310]
]

for prices in ohlc[1:]:
    if prices[-1] >= prices[0]:
        print(prices[-1])
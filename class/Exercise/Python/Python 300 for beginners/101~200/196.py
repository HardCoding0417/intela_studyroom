ohlc = [
    ["open", "hgih", "low", "close"],
    [100, 110, 70, 100],
    [200, 210, 180, 190],
    [300, 310, 300, 310]
]

for i in range(1, len(ohlc)):
    if ohlc[i][-1] > 150:
        print(ohlc[i][-1])
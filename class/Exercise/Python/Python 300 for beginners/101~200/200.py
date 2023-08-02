ohlc = [
    ["open", "high", "low", "close"],
    [100, 110, 70, 100],
    [200, 210, 180, 190],
    [300, 310, 300, 310]
]

sum = 0
for prices in ohlc[1:]:
    sum += prices[-1] - prices[0]

print(sum)
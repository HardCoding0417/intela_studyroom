ohlc = [
    ["open", "high", "low", "close"],
    [100, 110, 70, 100],
    [200, 210, 180, 190],
    [300, 310, 300, 310]
]

volatility = []
for prices in ohlc[1:]:
    volatility.append(prices[1] - prices[2])

print(volatility)
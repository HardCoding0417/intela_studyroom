low_prices = [100, 200, 400, 800, 1000]
high_prices = [150, 300, 430, 880, 1000]
day_cnt = len(high_prices)

volatility = [None]*day_cnt
for i in range(day_cnt):
    volatility[i] = high_prices[i] - low_prices[i]
print(volatility)
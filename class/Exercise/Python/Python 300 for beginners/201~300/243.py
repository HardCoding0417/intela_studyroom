import datetime

for day_past in range(5, 0, -1):
    print(datetime.datetime.now() - datetime.timedelta(day_past))
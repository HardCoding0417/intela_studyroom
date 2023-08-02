import csv


f = open('D:\\Users\\net02\\Desktop\\매수종목.csv', 'w', newline = '')
wr = csv.writer(f)

wr.writerow(('종목명', '종목코드', 'PER'))
wr.writerow(('삼성전자', '005930', 15.79))
wr.writerow(('NAVER', '035420', 55.82))

f.close()
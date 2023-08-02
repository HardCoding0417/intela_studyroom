class Stock:
    def __init__(self, name: str, code: str, PER: float, PBR: float, dividend: float):
        self.name = name
        self.code = code
        self.PER = PER
        self.PBR = PBR
        self.dividend = dividend
    
    def set_name(self, name: str) -> None:
        self.name = name
    def set_code(self, code: str) -> None:
        self.code = code
    def set_per(self, PER: float) -> None:
        self.PER = PER
    def set_pbr(self, PBR: float) -> None:
        self.PBR = PBR
    def set_dividend(self, dividend: float) -> None:
        self.dividend = dividend

    def get_name(self) -> str:
        return self.name
    def get_code(self) -> str:
        return self.code
    

stocks = []    
stocks.append(Stock("삼성전자", "005930", 15.79, 1.33, 2.83))
stocks.append(Stock("현대차", "005380", 8.7, .35, 4.27))
stocks.append(Stock("LG전자", "066570", 317.34, .69, 1.37))

for stock in stocks:
    print(stock.get_code(), stock.PER)
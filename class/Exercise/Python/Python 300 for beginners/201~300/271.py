import random as r



class Account:
    bank_name = 'SC'

    cnt = 0


    def __init__(self, name: str, balance: int):
        self.name = name
        self.balance = balance
        self.account = '-'.join((str(r.randint(0, 999)).zfill(3), str(r.randint(0, 99)).zfill(2), str(r.randint(0, 999999)).zfill(6)))

        self.deposit_cnt = 0

        self.deposit_list = []
        self.withdraw_list = []

        Account.cnt += 1

        print(f"{self.name}'s balance: {self.balance}")
    
    @classmethod
    def get_account_num(cls) -> None:
        print(f"{cls.cnt} bank accounts in total")

    def deposit(self, amount: int) -> None:
        if not amount:
            print("You cannot deposit 0")
            return
        
        self.balance += amount
        self.deposit_list.append(amount)
        self.deposit_cnt += 1
        if self.deposit_cnt >= 5:
            self.deposit_cnt = 0
            self.deposit_list.append(int(self.balance*0.01))
            self.balance = int(self.balance*1.01)
        print(f"You deposited {amount}; {self.name}'s balance: {self.balance}")
    def withdraw(self, amount: int) -> None:
        if amount > self.balance:
            print(f"You cannot withdraw {amount} that exceeds your balance {self.balance}")
            return
        
        self.balance -= amount
        self.withdraw_list.append(amount)
        print(f"You withdrawed {amount}; {self.name}'s balance: {self.balance}")

    def deposit_history(self):
        print(f"<{self.name}'s deposit history>")
        for deposit in self.deposit_list:
            print(deposit)
    def withdraw_history(self):
        print(f"<{self.name}'s withdraw history>")
        for withdraw in self.withdraw_list:
            print(withdraw)

    def display_info(self):
        print(f"은행이름: {self.bank_name}은행\n예금주: {self.name}\n계좌번호: {self.account}\n잔고: {self.balance:,}")



ac1 = Account('Choi Myeongsu', 10000)

ac1.deposit(100)
ac1.deposit(200)
ac1.deposit(300)
ac1.deposit(400)
ac1.deposit(500)

ac1.withdraw(5000)

ac1.deposit_history()
ac1.withdraw_history()
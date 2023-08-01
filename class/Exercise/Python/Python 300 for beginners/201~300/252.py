class Human:
    def __init__(self, name, age, sex):
        self.name = name
        self.age = age
        self.sex = sex

    def __del__(self):
        print("나의 죽음을 널리 알려라")

    
    def setInfo(self, name, age, sex):
        self.name = name
        self.age = age
        self.sex = sex

    def who(self):
        print(f"이름: {self.name}, 나이: {self.age}, 성별: {self.sex}")


isocy = Human('Chuel Mingsiu', 20, 'female')
isocy.who()

isocy.setInfo('Choi Myeongsu', 20, 'male')
isocy.who()

del isocy
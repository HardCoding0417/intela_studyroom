class Car:
    def __init__(self, value1, value2):
        self.content = self # 'self' is the instance

        self.color = value1
        self.speed = value2
    
    def upSpeed(self, value):
        self.speed += value
    
    def downSpeed(self, value):
        self.speed -= value


myCar1 = Car('red', 30)
myCar2 = Car('blue', 60)

print(myCar1)
print(myCar1.content)

print(type(myCar1))
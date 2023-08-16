from enum import Enum, auto

# Component 추상 클래스
class Beverage:
    description = ''

    class Size(Enum):
        TALL=auto(),
        GRANDE=auto(),
        VENTI=auto()
    size = Size.TALL

    def __init__(self):
        pass

    def getDescrition(self):
        return self.description
    
    def cost(self):
        pass

    def setSize(self, size):
        self.size = size
        
    def getSize(self):
        return self.size

class HouseBlend(Beverage):
    def __init__(self):
        self.description = '하우스 블렌드 커피'

    def cost(self):
        return .89

class Espresso(Beverage):
    def __init__(self):
        self.description = '에스프레소'

    def cost(self):
        return 1.99

class DarkRoast(Beverage):
    def __init__(self):
        self.description = '다크 로스트'

    def cost(self):
        return .99

class Decaf(Beverage):
    def __init__(self):
        self.description = '디카페인'

    def cost(self):
          return 1.05

# Decorator 추상 클래스
class CondimentDecorator(Beverage):
    beverage = Beverage()

    def __init__(self, beverage):
        pass
        
    def getDescrition(self):
        pass

    def getSize(self):
        return self.beverage.getSize()

class Milk(CondimentDecorator):

    def __init__(self, beverage):
        self.beverage = beverage

    def cost(self):
        cost = self.beverage.cost()
        if self.beverage.getSize() == self.Size.TALL :
            cost += .10
        elif self.beverage.getSize() == self.Size.GRANDE :
            cost += .15
        elif self.beverage.getSize() == self.Size.VENTI :
            cost += .20
        
        return cost

    def getDescrition(self):
        return self.beverage.getDescrition() + ', 우유'

class Mocha(CondimentDecorator):

    def __init__(self, beverage):
        self.beverage = beverage

    def cost(self):
        cost = self.beverage.cost()
        if self.beverage.getSize() == self.Size.TALL :
            cost += .20
        elif self.beverage.getSize() == self.Size.GRANDE :
            cost += .25
        elif self.beverage.getSize() == self.Size.VENTI :
            cost += .30
        
        return cost

    def getDescrition(self):
        return self.beverage.getDescrition() +', 모카'

class Soy(CondimentDecorator):

    def __init__(self, beverage):
        self.beverage = beverage

    def cost(self):
        cost = self.beverage.cost()
        if self.beverage.getSize() == self.Size.TALL :
            cost += .15
        elif self.beverage.getSize() == self.Size.GRANDE :
            cost += .20
        elif self.beverage.getSize() == self.Size.VENTI :
            cost += .25
        
        return cost

    def getDescrition(self):
        return self.beverage.getDescrition() + ', 두유'

class Whip(CondimentDecorator):

    def __init__(self, beverage):
        self.beverage = beverage

    def cost(self):
        cost = self.beverage.cost()
        if self.beverage.getSize() == self.Size.TALL :
            cost += .10
        elif self.beverage.getSize() == self.Size.GRANDE :
            cost += .15
        elif self.beverage.getSize() == self.Size.VENTI :
            cost += .20
        
        return cost

    def getDescrition(self):
        return self.beverage.getDescrition() + ', 휘핑크림'

if __name__ == "__main__":
    beverage = Espresso()
    print(beverage.getDescrition() + ' $' + '%.2f'%(beverage.cost()))

    beverage2 = DarkRoast()
    beverage2.setSize(beverage2.Size.GRANDE)
    beverage2 = Mocha(beverage2)
    beverage2 = Mocha(beverage2)
    beverage2 = Whip(beverage2)
    print(beverage2.getDescrition()+ ' $'+'%.2f'%(beverage2.cost()))

    beverage3 = HouseBlend()
    beverage3.setSize(beverage3.Size.VENTI)
    beverage3 = Soy(beverage3)
    beverage3 = Mocha(beverage3)
    beverage3 = Whip(beverage3)
    print(beverage3.getDescrition()+ ' $'+'%.2f'%(beverage3.cost()))
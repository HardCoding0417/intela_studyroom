# 자바에서는 다중 상속을 지원하지 않기 때문에 인터페이스를 활용해서 다중 상속과 동일한 기능을 구현
# 파이썬에서는 다중 상속을 지원
# 파이썬에서는 인터페이스를 지원하지 않기 때문에 추상클래스로 인터페이스 형태를 구현

# FlyBehavior : 나는 행동을 구현할 추상클래스
class FlyBehavior():
    def fly(self):
        pass

# FlyWithWings, FlyNoWay, FlyRocketPowered : Flybehavior를 상속받아 기능을 구현할 클래스
class FlyWithWings(FlyBehavior):
    def fly(self):
        print("날개를 활짝 펴고 세상을 자유롭게 날거야")

class FlyNoWay(FlyBehavior):
    def fly(self):
        print("오리는 날 수 없다 엄마에게 혼났죠")

class FlyRocketPowered(FlyBehavior):
    def fly(self):
        print("로켓 추진으로 날아갑니다")

# QuackBehavior : 우는 소리를 내는 행동을 구현할 추상클래스
class QuackBehavior():
    def quack(self):
        pass

# Quack, Squack, MuteQuack : QuackBehavior를 상속받아 기능을 구현할 클래스
class Quack(QuackBehavior):
    def quack(self):
        print("꽥")
    
class Squack(QuackBehavior):
    def quack(self):
        print("삑")

class MuteQuack(QuackBehavior):
    def quack(self):
        print("<< 조용~ >>")

# Duck : 오리 슈퍼클래스 
class Duck:
    # 행동 추상클래스 형식의 클래스 변수 선언
    flyBehavior = FlyBehavior()
    quackBehavior = QuackBehavior()
    
    def __init__(self):
        pass    
    
    # setFlyBehavior, setQuackBehavior : setter 메서드로 호출하는 방법
    def setFlyBehavior(self, fb):
        self.flyBehavior = fb
    
    def setQuackBehavior(self, qb):
        self.quackBehavior = qb

    def performQuack(self):
        self.quackBehavior.quack()

    def performFly(self):
        self.flyBehavior.fly()

    def display(self):
        pass

    def swim(self):
        print("모든 오리는 물에 뜹니다. 가짜 오리도 뜨죠")

# MallardDuck : 오리 클래스를 상속받은 물오리 클래스
class MallardDuck(Duck):
    def __init__(self):
        # 우는 행동과 나는 행동을 특정해서 변수 선언
        self.quackBehavior = Quack()
        self.flyBehavior = FlyWithWings()

    def display(self):
        print("저는 물오리입니다.")

class ModelDuck(Duck):
    def __init__(self):
        self.flyBehavior = FlyNoWay()
        self.quackBehavior = Quack()
    
    def display(self):
        print("저는 모형 오리입니다.")

# 실행
if __name__ == "__main__":
    mallard = MallardDuck()
    mallard.performQuack()
    mallard.performFly()

    model = ModelDuck()
    model.performFly()
    # setter 메서드로 동적으로 행동 지정하기
    model.setFlyBehavior(FlyRocketPowered())
    model.performFly()
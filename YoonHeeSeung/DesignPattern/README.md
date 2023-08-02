# HeadFirst 디자인패턴 (Python)

Chapter 1. 

* 원칙 1. 변화하는 부분을 찾아내고, 변화하지 않는 부분과 분리한다.
* 원칙 2. 구현보다는 인터페이스에 맞춰서 프로그래밍한다.
* 원칙 3. 상속보다는 구성(composition)을 활용한다.

[전략패턴](./strategy.py) Duck 클래스, FlyBehavior, QuackBehavior 인터페이스 구현

1. 알고리즘군(ex. FlyBehavior, QuackBehavior)을 정의하고 캡슐화해서 각각의 알고리즘군을 수정해서 쓸 수 있게 해준다. 
2. 클라이언트(Duck 클래스)로부터 알고리즘을 분리해서 독립적으로 변경할 수 있다.

[p.61 전략패턴 예제](./strategy2.py) Character 클래스, WeaponBehavior 인터페이스 구현


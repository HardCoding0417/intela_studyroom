
# 무기에 따른 행동을 구현할 인터페이스
class WeaponBehavior:
    def __init__(self):
        pass

    def useWeapon(self):
        pass

# KnifeBehavior, AxeBehavior, SwordBehavior, BowAndArrowBehavior : 무기에 따른 행동을 구현한 클래스
class KnifeBehavior(WeaponBehavior):
    def useWeapon(self):
        print("칼로 벱니다.")

class AxeBehavior(WeaponBehavior):
    def useWeapon(self):
        print("도끼로 내려찍습니다.")

class SwordBehavior(WeaponBehavior):
    def useWeapon(self):
        print("검으로 휘두릅니다.")

class BowAndArrowBehavior(WeaponBehavior):
    def useWeapon(self):
        print("활로 화살을 쏩니다.")

# 클라이언트 : 슈퍼클래스(추상클래스)
class Character:

    weaponBehavior = WeaponBehavior()

    def __init__(self):
        pass

    def setWeapon(self, wb):
        self.weaponBehavior = wb

    def fight(self):
        pass

# Queen, King, Troll, Knight : Character 클래스를 상속
class Queen(Character):

    def __init__(self):
        self.weaponBehavior = BowAndArrowBehavior()

    def fight(self):
        print("여왕이 공격합니다.")
        self.weaponBehavior.useWeapon()

class King(Character):
    def __init__(self):
        self.weaponBehavior = KnifeBehavior()

    def fight(self):
        print("왕이 공격합니다.")
        self.weaponBehavior.useWeapon()

class Troll(Character):
    def __init__(self):
        self.weaponBehavior = AxeBehavior()

    def fight(self):
        print("트롤이 공격합니다.")
        self.weaponBehavior.useWeapon()

class Knight(Character):
    def __init__(self):
        self.weaponBehavior = SwordBehavior()

    def fight(self):
        print("기사가 공격합니다.")
        self.weaponBehavior.useWeapon()

# 실행
if __name__ == "__main__":
    knight = Knight()
    knight.fight()
    troll = Troll()
    troll.fight()
    knight.setWeapon(BowAndArrowBehavior())
    knight.fight()
    
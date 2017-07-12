# -*- coding:UTF-8 -*-


class FlyBehavior:
    def __init__(self):
        pass

    def fly(self):
        raise NotImplementedError


class FlyWithWings(FlyBehavior):
    def __init__(self):
        FlyBehavior.__init__(self)

    def fly(self):
        print 'I am flying'


class FlyNoWay(FlyBehavior):
    def __init__(self):
        FlyBehavior.__init__(self)

    def fly(self):
        print 'I can\'t fly'


class FlyRocketPowered(FlyBehavior):
    def __init__(self):
        FlyBehavior.__init__(self)

    def fly(self):
        print 'I am flying with a rocket!'


class QuackBehavior:
    def __init__(self):
        pass

    def quack(self):
        raise NotImplementedError


class Quack(QuackBehavior):
    def __init__(self):
        QuackBehavior.__init__(self)

    def quack(self):
        print 'Quack'


class MuteQuack(QuackBehavior):
    def __init__(self):
        QuackBehavior.__init__(self)

    def quack(self):
        print '<<slience>>'


class Squeak(QuackBehavior):
    def __init__(self):
        QuackBehavior.__init__(self)

    def quack(self):
        print 'Squeak'


class Duck:
    def __init__(self):
        self._fly_behavior = None
        self._quack_behavior = None

    def display(self):
        raise NotImplementedError

    def swim(self):
        print 'All ducks float,even decoys!'

    def perform_quack(self):
        self._quack_behavior.quack()

    def perform_fly(self):
        self._fly_behavior.fly()

    def set_quack_behavior(self, quack):
        self._quack_behavior = quack

    def set_fly_behavior(self, fly):
        self._fly_behavior = fly


class MallardDuck(Duck):
    def __init__(self):
        Duck.__init__(self)
        self.set_quack_behavior(Quack())
        self.set_fly_behavior(FlyWithWings())

    def dispaly(self):
        print 'I am a real Mallard Duck'


class ModelDuck(Duck):
    def __init__(self):
        Duck.__init__(self)
        self.set_quack_behavior(Quack())
        self.set_fly_behavior(FlyNoWay())

    def display(self):
        print 'I am a Model Duck'


mallard = MallardDuck()
mallard.dispaly()
mallard.perform_quack()
mallard.perform_fly()

model = ModelDuck()
model.display()
model.perform_quack()
model.perform_fly()
model.set_fly_behavior(FlyRocketPowered())
model.perform_fly()



class Duck:
    def quack(self):
        raise NotImplementedError

    def fly(self):
        raise NotImplementedError

class MallardDuck(Duck):
    def quack(self):
        print 'Quack'

    def fly(self):
        print 'I\'m flying'

class Turkey:
    def gobble(self):
        raise NotImplementedError

    def fly(self):
        raise NotImplementedError

class WildTurkey(Turkey):
    def gobble(self):
        print 'Gooble gobble'

    def fly(self):
        print 'I am flying a shot distance'

class TurkeyAdapter(Duck):
    def __init__(self, turkey):
        self.turkey = turkey

    def quack(self):
        self.turkey.gobble()

    def fly(self):
        self.turkey.fly()
        self.turkey.fly()
        self.turkey.fly()
        self.turkey.fly()
        self.turkey.fly()

duck = MallardDuck()
turkey = WildTurkey()
turkeyAdapter = TurkeyAdapter(turkey)

print 'The Turkey says...'
turkey.gobble()
turkey.fly()

print 'The Duck says...'
duck.quack()
duck.fly()

print 'The TurkeyAdapter says...'
turkeyAdapter.quack()
turkeyAdapter.fly()


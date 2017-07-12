class CaffeineBeverage:
    def prepareRecope(self):
        self.boilWater()
        self.brew()
        self.pourInCup()
        self.addCondiments()

    def brew(self):
        raise NotImplementedError

    def addCondiments(self):
        raise NotImplementedError

    def boilWater(self):
        print 'Boiling water'

    def pourInCup(self):
        print 'Pouring into cup'

class Tea(CaffeineBeverage):
    def brew(self):
        print 'Steeping the tea'

    def addCondiments(self):
        print 'Adding Lemon'

class Coffee(CaffeineBeverage):
    def brew(self):
        print 'Dripping Coffee through filter'

    def addCondiments(self):
        print 'Adding Sugar and Milk'


myTea = Tea()
myTea.prepareRecope()

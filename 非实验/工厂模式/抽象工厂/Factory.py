class Garlic:
    pass


class Onion:
    pass


class Mushroom:
    pass


class RedPepper:
    pass


class Dough:
    pass


class Sauce:
    pass


class Cheese:
    pass


class Clams:
    pass


class Pepperoni:
    pass


class ThickCrustDough(Dough):
    pass


class ThinCrustDough(Dough):
    pass


class PlumTomatoSauce(Sauce):
    pass


class MarinaraSauce:
    pass


class MozzarellaCheese(Cheese):
    pass


class ReggianoCheese(Cheese):
    pass


class FrozenClams(Clams):
    pass


class FreshClams(Clams):
    pass


class SlicedPepperoni(Pepperoni):
    pass


class PizzaIngredientFactory:
    def creatDough(self):
        raise NotImplementedError

    def creatSauce(self):
        raise NotImplementedError

    def creatCheese(self):
        raise NotImplementedError

    def creatVeggies(self):
        raise NotImplementedError

    def creatPepperoni(self):
        raise NotImplementedError

    def creatClam(self):
        raise NotImplementedError


class NYPizzaIngredientFactory(PizzaIngredientFactory):
    def creatDough(self):
        return ThinCrustDough()

    def creatSauce(self):
        return MarinaraSauce()

    def creatCheese(self):
        return ReggianoCheese()

    def creatClam(self):
        return FreshClams()

    def creatPepperoni(self):
        return SlicedPepperoni()

    def creatVeggies(self):
        return [Garlic(), Onion(), Mushroom(), RedPepper()]


class ChicagoPizzaIngredientFactory(PizzaIngredientFactory):
    def creatDough(self):
        return ThickCrustDough()

    def creatSauce(self):
        return PlumTomatoSauce()

    def creatCheese(self):
        return MarinaraSauce()

    def creatClam(self):
        return FrozenClams()

    def creatPepperoni(self):
        return SlicedPepperoni()

    def creatVeggies(self):
        return [Garlic(), Onion(), Mushroom(), RedPepper()]


class Pizza:
    name, dough, sauce, veggies, cheese, pepperoni, clam = None, None, None, None, None, None, None

    def prepare(self):
        raise NotImplementedError

    def bake(self):
        print 'Bake fo 25 minutes at 350'

    def cut(self):
        print 'Cutting the pizza into diagonal slices'

    def box(self):
        print 'Place pizza in official PizzaStore box'

    def setName(self, name):
        self.name = name

    def getName(self):
        return self.name


class CheesePizza(Pizza):
    def __init__(self, ingredientFactory):
        self.name = 'NY Style Sauce and Cheese Pizza'
        self.dough = 'Thin Crust Dough'
        self.sauce = 'Marinara Sauce'
        self.ingredientFactory = ingredientFactory

    def prepare(self):
        print 'Prepaing ' + self.name
        self.dough = self.ingredientFactory.creatDough()
        self.sauce = self.ingredientFactory.creatSauce()
        self.cheese = self.ingredientFactory.creatCheese()
        self.clam = self.ingredientFactory.creatClam()

class ClamPizza(Pizza):
    def __init__(self, ingredientFactory):
        self.ingredientFactory = ingredientFactory

    def prepare(self):
        print 'Prepaing ' + self.name
        self.dough = self.ingredientFactory.creatDough()
        self.sauce = self.ingredientFactory.creatSaucr()
        self.cheese = self.ingredientFactory.creatCheese()
        self.clam = self.ingredientFactory.creatClam()

class PizzaStore():
    def order_pizza(self, name):
        pizza = self.create_pizza(name)
        pizza.prepare()
        pizza.bake()
        pizza.cut()
        pizza.box()
        return pizza

    def create_pizza(self, name):
        pass

class NYPizzaStore(PizzaStore):
    def create_pizza(self, name):
        ingredientFactory = NYPizzaIngredientFactory()
        if name == 'cheese':
            pizza = CheesePizza(ingredientFactory)
            print 'New York Style Cheese Pizza'
        elif name == 'clam':
            pizza = ClamPizza(ingredientFactory)
            print 'New York Style Clam Pizza'
        return pizza

nyPizzaStore = NYPizzaStore()
nyPizzaStore.order_pizza('cheese')

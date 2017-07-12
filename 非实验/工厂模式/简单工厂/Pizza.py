# -*- coding:UTF-8 -*-

class Pizza():
    name, dough, sauce, toppings = None, None, None, []

    def prepare(self):
        print 'Preparing' + self.name
        print 'tossing dough...'
        print 'Adding sauce'
        print 'Adding toppings: '
        for each in self.toppings:
            print "   " + each

    def bake(self):
        print 'Bake for 25 minutes at 350'

    def cut(self):
        print 'Cutting the pizza into diagonal slices'

    def box(self):
        print 'Place pizza in official PizzaStore box'

    def get_name(self):
        return self.name

class NYStyleCheesePizza(Pizza):
    def __init__(self):
        self.name = 'NY Style Sauce and Cheese Pizza'
        self.dough = 'Thin Crust Dough'
        self.sauce = 'Marinara Sauce'
        self.toppings.append('Grated Reggiano Cheese')

class NYStyleVeggiePizza(Pizza):
    def __init__(self):
        self.name = 'NY Style Veggie Pizza'
        self.dough = 'Thin Crust Dough'
        self.sauce = 'Marinara Sauce'
        self.toppings.append('Grated Reggiano Cheese')

class NYStyleClamPizza(Pizza):
    def __init__(self):
        self.name = 'NY Style Clam Pizza'
        self.dough = 'Thin Crust Dough'
        self.sauce = 'Marinara Sauce'
        self.toppings.append('Grated Reggiano Cheese')

class NYStylePepperoni(Pizza):
    def __init__(self):
        self.name = 'NY Style Pepperoni Pizza'
        self.dough = 'Thin Crust Dough'
        self.sauce = 'Marinara Sauce'
        self.toppings.append('Grated Reggiano Cheese')

class ChicagoStyleCheesePizza(Pizza):
    def __init__(self):
        self.name = 'Chicago Style Deep Dish Cheese Pizza'
        self.dough = 'Extra Thick Crust Dough'
        self.sauce = 'Plum Tomato Sauce'
        self.toppings.append("Shredded Mozzarella Cheese")

    def cut(self):
        print 'Cutting the pizza into square slices'

class ChicagoStyleVeggiePizza(Pizza):
    def __init__(self):
        self.name = 'Chicago Style Veggie Cheese Pizza'
        self.dough = 'Extra Thick Crust Dough'
        self.sauce = 'Plum Tomato Sauce'
        self.toppings.append("Shredded Mozzarella Cheese")

    def cut(self):
        print 'Cutting the pizza into square slices'

class ChicagoStyleClamPizza(Pizza):
    def __init__(self):
        self.name = 'Chicago Style Clam Cheese Pizza'
        self.dough = 'Extra Thick Crust Dough'
        self.sauce = 'Plum Tomato Sauce'
        self.toppings.append("Shredded Mozzarella Cheese")

    def cut(self):
        print 'Cutting the pizza into square slices'

class ChicagoStylePepperoni(Pizza):
    def __init__(self):
        self.name = 'Chicago Style Pepperoni Cheese Pizza'
        self.dough = 'Extra Thick Crust Dough'
        self.sauce = 'Plum Tomato Sauce'
        self.toppings.append("Shredded Mozzarella Cheese")

    def cut(self):
        print 'Cutting the pizza into square slices'

class PizzaStore():
    def order_pizza(self, name):
        pizza = self.create_pizza(name)
        pizza.prepare()
        pizza.bake()
        pizza.cut()
        pizza.box()
        return pizza

    def create_pizza(self, name):
        raise NotImplementedError

class NYPizzaStore(PizzaStore):
    def create_pizza(self, name):
        if name == 'cheese':
            return NYStyleCheesePizza()
        elif name == 'veggie':
            return NYStyleVeggiePizza()
        elif name == 'clam':
            return NYStyleClamPizza()
        elif name == 'pepperoni':
            return NYStylePepperoni()
        else:
            return None


class ChicagoPizzaStore(PizzaStore):
    def create_pizza(self, name):
        if name == 'cheese':
            return ChicagoStyleCheesePizza()
        elif name == 'veggie':
            return ChicagoStyleVeggiePizza()
        elif name == 'clam':
            return ChicagoStyleClamPizza()
        elif name == 'pepperoni':
            return ChicagoStylePepperoni()
        else:
            return None

nyStore = NYPizzaStore()
chicagoStore = ChicagoPizzaStore()

pizza = nyStore.order_pizza('cheese')
print 'Ethan ordered a ' + pizza.get_name()

pizza = chicagoStore.order_pizza('cheese')
print 'Hoel ordered a ' + pizza.get_name()

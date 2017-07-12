class MenuItem:
    def __init__(self,name,description,vegetarian,price):
        self.name,self.description,self.vegetarian,self.price = name,description,vegetarian,price

    def getName(self):
        return self.name

    def getDescription(self):
        return self.description

    def getPrice(self):
        return self.price

    def isVegetarian(self):
        return self.vegetarian

class Iterator:
    def hasNext(self):
        raise NotImplementedError
    def next(self):
        raise NotImplementedError

class PancakeHouseMenuIterator(Iterator):
    def __init__(self, items):
        self.items = items
        self.postion = 0

    def hasNext(self):
        return self.postion < len(self.items)

    def next(self):
        item = self.items[self.postion]
        self.postion = self.postion + 1
        return item


class DinerMenuIterator(Iterator):
    def __init__(self, items):
        self.items = items
        self.postion = 0

    def hasNext(self):
        return self.postion < 4

    def next(self):
        item = self.items[self.postion]
        self.postion = self.postion + 1
        return item

class PancakeHouseMenu:
    def __init__(self):
        self.menuItems = []
        self.addItem("K&B Pancake Breakfast", "Pancakes with scrambled eggs and toast", True, 2.99)
        self.addItem("regular Pancake Breakfast", "Pancakes with fried eggs, sausage", False, 2.99)
        self.addItem("Blueberry Pancakes", "Pancakse made with fresh blueberries", True, 3.49)
        self.addItem("Waffles", "Waffles, with your choice of blueberries or strawberries", True, 3.59)

    def addItem(self,name,des,veg,price):
        self.menuItems.append(MenuItem(name,des,veg,price))

    def createIterator(self):
        return PancakeHouseMenuIterator(self.menuItems)

class DinerMenu:
    MAX_ITEMS = 6
    def __init__(self):
        self.menuItems = []
        self.numberOfItems = 0
        self.addItem("Vegetarian BLT", "(Fakin) Bacon with lettuce & tomato on whole wheat", True, 2.99)
        self.addItem("BLT", "Bacon with lettuce & tomato on whole wheat", False, 2.99)
        self.addItem("Soup of the day", "Soup of the day, with a side of potato salad", False, 3.29)
        self.addItem("Hotdog", "A hot dog, with saurkraut, relish, onions, topped with cheese", False, 3.05)

    def addItem(self, name, des, veg, price):
        self.menuItems.append(MenuItem(name, des, veg, price))

    def createIterator(self):
        return DinerMenuIterator(self.menuItems)

class Waitress:
    def __init__(self,pan,din):
        self.pancakeHouseMenu, self.dinerMenu = pan,din

    def Print(self):
        pancakeIterator = self.pancakeHouseMenu.createIterator()
        dinerIterator = self.dinerMenu.createIterator()
        print "MENU\n----\nBreakfast"
        self.printMenu(pancakeIterator)
        print "LUNCH"
        self.printMenu(dinerIterator)

    def printMenu(self,iterator):
        while iterator.hasNext():
            item = iterator.next()
            print item.getName() + ", " + item.getDescription() + ", " + str(item.getPrice())

pancakeHouseMenu = PancakeHouseMenu()
dinerMenu = DinerMenu()
waitress = Waitress(pancakeHouseMenu,dinerMenu)
waitress.Print()
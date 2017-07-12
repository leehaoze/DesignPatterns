class MenuComponent:
    def add(self, menuComponet):
        pass

    def remove(self, menuComponet):
        pass

    def getChild(self, i):
        pass

    def getDescription(self):
        pass

    def getPrice(self):
        pass

    def isVegetarian(self):
        pass

    def Print(self):
        pass


class MenuItem(MenuComponent):
    def __init__(self, name, description, vegetarian, price):
        self.name, self.description, self.vegetarian, self.price = name, description, vegetarian, price

    def getName(self):
        return self.name

    def getDescription(self):
        return self.description

    def getPrice(self):
        return self.price

    def isVegetarian(self):
        return self.vegetarian

    def Print(self):
        print " " + self.getName() + str(self.isVegetarian()) + ", " + str(
            self.getPrice()) + "   ----  " + self.getDescription()


class Menu(MenuComponent):
    def __init__(self, name, description):
        self.menuComponents = []
        self.name = name
        self.description = description

    def add(self, menuComponent):
        self.menuComponents.append(menuComponent)

    def remove(self, menuComponent):
        self.menuComponents.remove(menuComponent)

    def getChild(self, i):
        return self.menuComponents[i]

    def getName(self):
        return self.name

    def getDescription(self):
        return self.description

    def Print(self):
        print "+++++++" + self.getName() + ", " + self.getDescription() + "+++++++"
        for each in self.menuComponents:
            each.Print()


class Waitress:
    def __init__(self, allMenus):
        self.allMenus = allMenus

    def printMenu(self):
        self.allMenus.Print()


pancakeHouseMenu = Menu("PANCAKE HOUSE MENU", "BREAKFAST")
dinerMenu = Menu("DINER MENu", "LUNCH")
cafeMenu = Menu("CAFE MENU", "DINNER")
dessertMenu = Menu("DESSERT MENU", "DESSERT OF COURSE!")

allMenus = Menu("ALL MENUS", "ALL MENUS COMBINED")

allMenus.add(pancakeHouseMenu)
allMenus.add(dinerMenu)
allMenus.add(cafeMenu)

pancakeHouseMenu.add(MenuItem("K&B Pancake Breakfast", "Pancakes with scrambled eggs and toast", True, 2.99))
pancakeHouseMenu.add(MenuItem("regular Pancake Breakfast", "Pancakes with fried eggs, sausage", False, 2.99))
pancakeHouseMenu.add(MenuItem("Blueberry Pancakes", "Pancakse made with fresh blueberries", True, 3.49))
pancakeHouseMenu.add(MenuItem("Waffles", "Waffles, with your choice of blueberries or strawberries", True, 3.59))

dinerMenu.add(MenuItem("Pasta", "Spaghetti with Marinara Sauce and a slice of sourdough bread", True, 3.89))
dinerMenu.add(MenuItem("Vegetarian BLT", "(Fakin) Bacon with lettuce & tomato on whole wheat", True, 2.99))
dinerMenu.add(MenuItem("BLT","Bacon with lettuce & tomato on whole wheat",False, 2.99))
dinerMenu.add(MenuItem("Soup of the day", "Soup of the day, with a side of potato salad", False, 3.29))
dinerMenu.add(MenuItem("Hotdog","A hot dog, with saurkraut, relish, onions, topped with cheese",False, 3.05))
dinerMenu.add(dessertMenu)

dessertMenu.add(MenuItem("Apple Pie", "Apple Pie with a flakey crust topped with vanilla ice cream", True, 1.59))
waitress = Waitress(allMenus)

waitress.printMenu()

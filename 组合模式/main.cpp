#include <vector>
#include "iostream"

using namespace std;

class MenuComponent {
public:
    virtual void add(MenuComponent* menuComponent) {}

    virtual void remove(MenuComponent* menuComponent) {}

    virtual MenuComponent* getChild(int i) {}

    virtual string getDescription() {}

    virtual double getPrice() {}

    virtual bool isVegetarian() {}

    virtual void Print() {
    }
};

class MenuItem : public MenuComponent {
private:
    string name_, description_;
    bool vegetarian_;
    double price_;
public:
    MenuItem(string name,string description,bool vegetarian,double price):name_(name),description_(description),vegetarian_(vegetarian),price_(price){}

    string getName() {
        return name_;
    }

    string getDescription() {
        return description_;
    }

    double getPrice() {
        return price_;
    }

    bool isVegetarian() {
        return vegetarian_;
    }

    void Print() {
        cout << " " + getName() << isVegetarian() << ", " << getPrice() << "   ----  " + getDescription() << endl;
    }
};

class Menu:public MenuComponent{
private:
    vector<MenuComponent*> menuComponents_;
    string name_,description_;
public:
    Menu(string name,string description):name_(name),description_(description){}

    void add(MenuComponent* menuComponent){
        menuComponents_.push_back(menuComponent);
    }
    void remove(MenuComponent* menuComponent){
//        menuComponents_.erase(menuComponent);
    }
    MenuComponent* getChild(int i){
        return menuComponents_[i];
    }
    string getName(){
        return name_;
    }
    string getDescription(){
        return description_;
    }
    void Print(){
        cout << "+++++++" << getName() + ", " + getDescription() + "+++++++" << endl;
        for (int i = 0; i < menuComponents_.size(); ++i) {
            menuComponents_[i]->Print();
        }
    }
};

class Waitress{
private:
    MenuComponent* allMenus_;
public:
    Waitress(MenuComponent* menus):allMenus_(menus){}

    void printMenu(){
        allMenus_->Print();
    }
};

int main(){
    MenuComponent* pancakeHouseMenu = new Menu("PANCAKE HOUSE MENU", "BREAKFAST");
    MenuComponent* dinerMenu = new Menu("DINER MENu", "LUNCH");
    MenuComponent* cafeMenu = new Menu("CAFE MENU", "DINNER");
    MenuComponent* dessertMenu = new Menu("DESSERT MENU", "DESSERT OF COURSE!");

    MenuComponent* allMenus = new Menu("ALL MENUS", "ALL MENUS COMBINED");

    allMenus->add(pancakeHouseMenu);
    allMenus->add(dinerMenu);
    allMenus->add(cafeMenu);

    pancakeHouseMenu->add(new MenuItem("K&B Pancake Breakfast", "Pancakes with scrambled eggs and toast", true, 2.99));
    pancakeHouseMenu->add(new MenuItem("regular Pancake Breakfast", "Pancakes with fried eggs, sausage", false, 2.99));
    pancakeHouseMenu->add(new MenuItem("Blueberry Pancakes", "Pancakse made with fresh blueberries", true, 3.49));
    pancakeHouseMenu->add(new MenuItem("Waffles", "Waffles, with your choice of blueberries or strawberries", true, 3.59));

    dinerMenu->add(new MenuItem("Pasta", "Spaghetti with Marinara Sauce and a slice of sourdough bread", true, 3.89));
    dinerMenu->add(new MenuItem("Soup of the day", "Soup of the day, with a side of potato salad", false, 3.29));
    dinerMenu->add(new MenuItem("Hotdog","A hot dog, with saurkraut, relish, onions, topped with cheese",false, 3.05));
    dinerMenu->add(dessertMenu);

    dessertMenu->add(new MenuItem("Apple Pie", "Apple Pie with a flakey crust topped with vanilla ice cream", true, 1.59));
    Waitress waitress(allMenus);

    waitress.printMenu();

}
//        addItem("K&B Pancake Breakfast", "Pancakes with scrambled eggs and toast", true, 2.99);
//        addItem("regular Pancake Breakfast", "Pancakes with fried eggs, sausage", false, 2.99);
//        addItem("Blueberry Pancakes", "Pancakse made with fresh blueberries", true, 3.49);
//        addItem("Waffles", "Waffles, with your choice of blueberries or strawberries", true, 3.59);


//        addItem("Vegetarian BLT", "(Fakin) Bacon with lettuce & tomato on whole wheat", true, 2.99);
//        addItem("BLT","Bacon with lettuce & tomato on whole wheat",false, 2.99);
//        addItem("Soup of the day", "Soup of the day, with a side of potato salad", false, 3.29);
//        addItem("Hotdog","A hot dog, with saurkraut, relish, onions, topped with cheese",false, 3.05);



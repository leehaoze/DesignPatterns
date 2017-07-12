#include <vector>
#include "iostream"

using namespace std;

class MenuItem{
private:
    string name_;
    string description_;
    bool vegetarian_;
    double price_;
public:
    MenuItem(){}
    MenuItem(string name,string description, bool vegetarian, double price):name_(name),description_(description),vegetarian_(vegetarian),price_(price){}

    string getName(){
        return name_;
    }

    string getDescription(){
        return description_;
    }

    double getPrice(){
        return price_;
    }

    bool isVegetarian(){
        return vegetarian_;
    }
};

class Iterator{
public:
    virtual bool hasNext()=0;
    virtual MenuItem next()=0;
};

class PancakeHouseMenuIterator:public Iterator{
private:
    vector<MenuItem> items_;
    int postion_;
public:
    PancakeHouseMenuIterator(vector<MenuItem> items):items_(items),postion_(0){}
    bool hasNext(){
        return postion_ < items_.size();
    }
    MenuItem next(){
        return items_[postion_++];
    }
};

class DinerMenuIterator:public Iterator{
private:
    MenuItem* items_;
    int postion_;
public:
    DinerMenuIterator(MenuItem * items):items_(items),postion_(0){}
    bool hasNext(){
        return postion_ < 4;
    }
    MenuItem next(){
        return items_[postion_++];
    }
};


class PancakeHouseMenu{
private:
    vector<MenuItem> menuItems;
public:
    PancakeHouseMenu(){
        addItem("K&B Pancake Breakfast", "Pancakes with scrambled eggs and toast", true, 2.99);
        addItem("regular Pancake Breakfast", "Pancakes with fried eggs, sausage", false, 2.99);
        addItem("Blueberry Pancakes", "Pancakse made with fresh blueberries", true, 3.49);
        addItem("Waffles", "Waffles, with your choice of blueberries or strawberries", true, 3.59);
    }

    void addItem(string name, string description, bool vegetarian, double price){
        menuItems.push_back(MenuItem(name,description,vegetarian,price));
    }

    vector<MenuItem> getMenuItems(){
        return menuItems;
    }

    Iterator* createIterator(){
        return new PancakeHouseMenuIterator(menuItems);
    }
};

class DinerMenu{
private:
    int MAX_ITEMS=6;
    MenuItem menuItems[6];
    int numberOfItems;
public:
    DinerMenu(){
        addItem("Vegetarian BLT", "(Fakin) Bacon with lettuce & tomato on whole wheat", true, 2.99);
        addItem("BLT","Bacon with lettuce & tomato on whole wheat",false, 2.99);
        addItem("Soup of the day", "Soup of the day, with a side of potato salad", false, 3.29);
        addItem("Hotdog","A hot dog, with saurkraut, relish, onions, topped with cheese",false, 3.05);
    }
    void addItem(string name, string description ,bool vegetarian, double price){
        MenuItem menuItem = MenuItem(name, description, vegetarian, price);
        if(numberOfItems >= MAX_ITEMS)
            cout << "Sorry, menu is full! Can\'t add item to menu" << endl;
        else {
            menuItems[numberOfItems++] = menuItem;
        }
    }

    MenuItem* getMenuItems(){
        return menuItems;
    }

    Iterator* createIterator(){
        return new DinerMenuIterator(menuItems);
    }

};

class Waitress{
private:
    PancakeHouseMenu pancakeHouseMenu_;
    DinerMenu dinerMenu_;
public:
    Waitress(PancakeHouseMenu pancakeHouseMenu,DinerMenu dinerMenu):pancakeHouseMenu_(pancakeHouseMenu),dinerMenu_(dinerMenu){}
    void printMenu(){
        Iterator* pancakeIterator = pancakeHouseMenu_.createIterator();
        Iterator* dinerIterator = dinerMenu_.createIterator();
        cout << "MENU\n----\nBreakfast\n";
        printMenu(pancakeIterator);
        cout << "LUNCH" << endl;
        printMenu(dinerIterator);
    }

    void printMenu(Iterator* iterator){
        while(iterator->hasNext()){
            MenuItem item = iterator->next();
            cout << item.getName() + ", " + item.getDescription() + ", " << item.getPrice() << endl;
        }
    }
};

int main(){
    PancakeHouseMenu pancakeHouseMenu = PancakeHouseMenu();
    DinerMenu dinerMenu = DinerMenu();
    Waitress waitress = Waitress(pancakeHouseMenu,dinerMenu);
    waitress.printMenu();
}

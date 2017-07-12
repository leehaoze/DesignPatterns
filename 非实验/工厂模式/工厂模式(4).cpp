#include<iostream>
#include<sstream>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<iomanip>
#include<typeinfo>
#include<algorithm>
#include<time.h>
#include<map>
#include<vector>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
#define inf 0x3f3f3f3f
#define PI 3.14
const int maxn = 1000 + 8;

/*
原料:
Dough
Sauce
Cheese
Veggies
Pepperoni
Clams
*/
class Dough
{
public:
    Dough(){}
    virtual void show() = 0;
};
class ThickCrustDough:virtual public Dough {
public:
    ThickCrustDough() {}
    void show() { printf(" ThickCrustDough,"); }
};
class ThinCrustDough:public Dough
{
public:
    ThinCrustDough(){  }
    void show() { printf(" ThinCrustDough,"); }
};
//***********************************
class Sauce
{
public:
    Sauce(){}
    virtual void show() = 0;
};
class PlumTomatoSause: public Sauce
{
public:
    PlumTomatoSause(){ }
    void show() { printf(" PlumTomatoSause,");}
};
class MarinaraSause:public Sauce
{
public:
    MarinaraSause(){ }
    void show() { printf(" MarinaraSause,");}
};
//***********************************
class Cheese
{
public:
    Cheese(){}
    virtual void show() = 0;
};
class MozzarellaCheese:public Cheese
{
public:
    MozzarellaCheese(){};
    void show(){ printf(" MarinaraSause,");}
};
class RegginaoCheese:public Cheese
{
public:
    RegginaoCheese(){};
    void show(){ printf(" MarinaraSause,");}
};
//***********************************
class Veggies
{
public:
    Veggies(){}
    virtual void show() = 0;
};
class Garlic:public Veggies
{
public:
    Garlic(){};
    void show(){ printf(" Garlic,");}
};
class Onion:public Veggies
{
public:
    Onion(){};
    void show(){ printf(" Onion,");}
};
class Mushroom:public Veggies
{
public:
    Mushroom(){};
    void show(){ printf(" Mushroom,");}
};
class RedPepper:public Veggies
{
public:
    RedPepper(){};
    void show(){ printf(" RedPepper,");}
};
class BlackOlives:public Veggies
{
public:
    BlackOlives(){};
    void show(){  printf(" BlackOlives,");}
};
class Spinach:public Veggies
{
public:
    Spinach(){};
    void show(){ printf(" Spinach,");}
};
class Eggplant:public Veggies
{
public:
    Eggplant(){};
    void show(){ printf(" Eggplant,");}
};
//***********************************
class Pepperoni
{
public:
    Pepperoni(){}
    virtual void show() = 0;

};
class SlicedPepperoni:public Pepperoni
{
public:
    SlicedPepperoni(){};
    void show(){ printf(" SlicedPepperoni,");}
};

//***********************************
class Clams
{
public:
    Clams(){}
    virtual void show() = 0;
};
class FrozenClams:public Clams
{
public:
    FrozenClams(){};
    void show(){ printf(" FrozenClams,");}
};
class FreshClams:public Clams
{
public:
    FreshClams(){};
    void show(){ printf(" FreshClams,");}
};
//************************************************************************
/*
原料工厂:
NYPizzaIngerdientFactory
ChicagoPizzaIngerdientFactory
 */
class PizzaIngerdientFactory{
public:
    virtual Dough* createDough() = 0;
    virtual Sauce* createSauce() = 0;
    virtual Cheese* createCheese() = 0;
    virtual Veggies** createVeggies() = 0;
    virtual Pepperoni* createPepperoni() = 0;
    virtual Clams* createClams() = 0;
};

class NYPizzaIngerdientFactory:public PizzaIngerdientFactory
{
public:
    Dough* createDough(){
        return new ThickCrustDough();
    }
    Sauce* createSauce(){
        return new MarinaraSause();
    }
    Cheese* createCheese(){
        return new RegginaoCheese();
    }
    Veggies** createVeggies(){
        Veggies **veggies = new Veggies* [4];
        veggies[0] = new Garlic();
        veggies[1] = new Onion();
        veggies[2] = new Mushroom();
        veggies[3] = new RedPepper();
        veggies[4] = NULL;
        return veggies;
    }
    Pepperoni* createPepperoni(){
        return new SlicedPepperoni();
    }
    Clams* createClams(){
        return new FreshClams();
    }
};
class ChicagoPizzaIngerdientFactory:public PizzaIngerdientFactory
{
public:
    Dough* createDough(){
        return new ThickCrustDough();
    }
    Sauce* createSauce(){
        return new PlumTomatoSause();
    }
    Cheese* createCheese(){
        return new MozzarellaCheese();
    }
    Veggies** createVeggies(){
        Veggies **veggies = new Veggies* [3];
        veggies[0] = new BlackOlives();
        veggies[1] = new Spinach();
        veggies[2] = new Eggplant();
        veggies[3] = NULL;
        return veggies;
    }
    Pepperoni* createPepperoni(){
        return new SlicedPepperoni();
    }
    Clams* createClams(){
        return new FrozenClams();
    }
};
//************************************************************************
/*
披萨:
ChessPizza
ClamPizza
VeggiePizza
PepperoniPizza
*/
class Pizza

{
protected:
    string name_;
    Dough *dough_;
    Sauce *sauce_;
    Cheese *cheese_;
    Veggies **veggies_;
    Pepperoni *pepperoni_;
    Clams *clams_;
public:
    Pizza(){}
public:
    void bake(){
        printf("Bake for 25 minutes at 350.\n");
    }
    void cut(){
        printf("Cutting the pizza into diagonal slices.\n");
    }
    void box(){
        printf("Place pizza in offical PizzaStore box.\n");
    }
    void name(string s){name_ = s;}
    string name() const{ return name_;}
    virtual void prepare() = 0;
    virtual void show() = 0;
};
class ChessPizza:public Pizza
{
protected:
    PizzaIngerdientFactory *ingredientFactory_;
public:
    ChessPizza(PizzaIngerdientFactory *i):ingredientFactory_(i){}
    void prepare()
    {
        cout <<"Preparing: " << name() << endl;
        dough_ = ingredientFactory_->createDough();
        sauce_ = ingredientFactory_->createSauce();
        cheese_ = ingredientFactory_->createCheese();
    }
    void show(){
        cout << "Our Ingredient: " ;
        dough_->show();
        sauce_->show();
        cheese_->show();
    }
};
class ClamPizza:public Pizza
{
protected:
    PizzaIngerdientFactory *ingredientFactory_;
public:
    ClamPizza(PizzaIngerdientFactory *i):ingredientFactory_(i){}
    void prepare()
    {
        cout <<"Preparing: " << name() << endl;
        dough_ = ingredientFactory_->createDough();
        sauce_ = ingredientFactory_->createSauce();
        cheese_ = ingredientFactory_->createCheese();
        clams_ = ingredientFactory_->createClams();
    }
    void show(){
        cout << "Our Ingredient: " ;
        dough_->show();
        sauce_->show();
        cheese_->show();
        clams_->show();
    }
};
class VeggiePizza:public Pizza
{
protected:
    PizzaIngerdientFactory *ingredientFactory_;
public:
    VeggiePizza(PizzaIngerdientFactory *i):ingredientFactory_(i){}
    void prepare()
    {
        cout <<"Preparing: " << name() << endl;
        dough_ = ingredientFactory_->createDough();
        sauce_ = ingredientFactory_->createSauce();
        cheese_ = ingredientFactory_->createCheese();
        veggies_ = ingredientFactory_->createVeggies();
    }
    void show(){
        cout << "Our Ingredient: " ;
        dough_->show();
        sauce_->show();
        cheese_->show();
        int pos = 0;
        while(veggies_[pos] != NULL)
        {
            veggies_[pos++]->show();
        }
    }
};
class PepperoniPizza:public Pizza
{
protected:
    PizzaIngerdientFactory *ingredientFactory_;
public:
    PepperoniPizza(PizzaIngerdientFactory *i):ingredientFactory_(i){}
    void prepare()
    {
        cout <<"Preparing: " << name() << endl;
        dough_ = ingredientFactory_->createDough();
        sauce_ = ingredientFactory_->createSauce();
        cheese_ = ingredientFactory_->createCheese();
        pepperoni_ = ingredientFactory_->createPepperoni();
    }
    void show(){
        cout << "Our Ingredient: " ;
        dough_->show();
        sauce_->show();
        cheese_->show();
        pepperoni_->show();
    }
};
//************************************************************************
/*
披萨店:
NYPizzaStore
ChicagoPizzaStore
 */
class PizzaStore
{
protected:
    Pizza *pizza_;
    PizzaIngerdientFactory *ingerdientFactory_;
public:
    Pizza* pizza () const { return pizza_;}
    PizzaStore(){}
    void orderPizza(string s)
    {
        pizza_ = createPizza(s);
        pizza_->bake();
        pizza_->cut();
        pizza_->box();
    }
    virtual Pizza* createPizza(string s) = 0;
};

class NYPizzaStore:public PizzaStore
{
public:
    Pizza* createPizza(string s)
    {
        Pizza *pizza = NULL;
        ingerdientFactory_ = new NYPizzaIngerdientFactory();
        if(s == "chess"){
            pizza = new ChessPizza(ingerdientFactory_);
            pizza->name("New York Style Chess Pizza");
        }
        else if(s == "veggie")
        {
            pizza = new VeggiePizza(ingerdientFactory_);
            pizza->name("New York Style Veggie Pizza");
        }else if(s == "clam"){
            pizza = new ClamPizza(ingerdientFactory_);
            pizza->name("New York Style Clam Pizza");
        }else //if( s ==  "pepperoni")
        {
            pizza = new PepperoniPizza(ingerdientFactory_);
            pizza->name("New York Style Pepperoni Pizza");
        }
        return pizza;
    }
};

class ChicagoPizzaStore:public PizzaStore
{
public:
    Pizza* createPizza(string s)
    {
        Pizza *pizza = NULL;
        ingerdientFactory_ = new ChicagoPizzaIngerdientFactory();
        if(s == "chess"){
            pizza = new ChessPizza(ingerdientFactory_);
            pizza->name("Chicago Style Chess Pizza");
        }
        else if(s == "veggie")
        {
            pizza = new VeggiePizza(ingerdientFactory_);
            pizza->name("Chicago Style Veggie Pizza");
        }else if(s == "clam"){
            pizza = new ClamPizza(ingerdientFactory_);
            pizza->name("Chicago Style Clam Pizza");
        }else //if( s ==  "pepperoni")
        {
            pizza = new PepperoniPizza(ingerdientFactory_);
            pizza->name("Chicago Style Pepperoni Pizza");
        }
        return pizza;
    }
};
//************************************************************************

int main()
{
    printf("Waiter: Welcome to our PizzaStore!\n");
    printf("Waiter: Here is the menu,sir/madam.\n");
    printf("Waiter: May I take your order now?\n\n");


    PizzaStore *pizzaStore;
    ///The First Costomer
    printf("Costomer: I need a New York Pizza.\n");
    printf("Costomer: I am eager to taste the chess pizza.\n");
    cout << "Our process: \n";
    pizzaStore = new NYPizzaStore();
    pizzaStore->orderPizza("chess");
    pizzaStore->pizza()->prepare();
    pizzaStore->pizza()->show();
    cout << endl<<endl;
    ///The Second Costomer
    printf("Costomer: I need a Chicago Pizza.\n");
    printf("Costomer: I am eager to taste the veggie pizza.\n");
    cout << "Our process: \n";
    pizzaStore = new ChicagoPizzaStore();
    pizzaStore->orderPizza("veggie");
    pizzaStore->pizza()->prepare();
    pizzaStore->pizza()->show();

    return 0;
}
/*
输出结果：
Waiter: Welcome to our PizzaStore!
Waiter: Here is the menu,sir/madam.
Waiter: May I take your order now?

Costomer: I need a New York Pizza.
Costomer: I am eager to taste the chess pizza.
Our process:
Bake for 25 minutes at 350.
Cutting the pizza into diagonal slices.
Place pizza in offical PizzaStore box.
Preparing: New York Style Chess Pizza
Our Ingredient:  ThickCrustDough, MarinaraSause, MarinaraSause,

Costomer: I need a Chicago Pizza.
Costomer: I am eager to taste the veggie pizza.
Our process:
Bake for 25 minutes at 350.
Cutting the pizza into diagonal slices.
Place pizza in offical PizzaStore box.
Preparing: Chicago Style Veggie Pizza
Our Ingredient:  ThickCrustDough, PlumTomatoSause, MarinaraSause, BlackOlives, Spinach, Eggplant,
*/
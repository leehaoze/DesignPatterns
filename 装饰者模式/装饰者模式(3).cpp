#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

class Beverage{
protected:
    string description;
public:
    string getDescription(){return description;}
    virtual double cost()  = 0;
public:
    Beverage(string d = ""):description(d){}
};

class HouseHold: public Beverage
{
public:
    HouseHold():Beverage("HouseHold "){}
public:
    string getDescription() {return description;}
    double cost()  { return 0.99; }
};


class DarkRoast: public Beverage
{
public:
    DarkRoast():Beverage("DarkRoast"){}
public:
    string getDescription() {return description;}
    double cost()  { return 1.99; }
};

class Espresso: public Beverage
{
public:
    Espresso():Beverage("Espresso"){}
public:
    string getDescription() {return description;}
    double cost()  { return 2.99; }
};

class Decaf: public Beverage
{
public:
    Decaf():Beverage("Decaf"){}
public:
    string getDescription() {return description;}
    double cost()  { return 3.99; }
};



class Condiment:public Beverage
{
protected:
    double exceedCost;
public:
    virtual string getDescription() = 0;
};

class Soy:public Condiment
{
public:
    Soy(Beverage *b){
        description = b->getDescription() + ", Soy";
        exceedCost = b->cost();
        }
public:
    string getDescription() {return description;}
    double cost()  { return 0.10 + exceedCost; }
};

class SteamedMilk:public Condiment
{
public:
    SteamedMilk(Beverage *b){
        description = b->getDescription() + ", SteamedMilk";
        exceedCost = b->cost();
        }
public:
    string getDescription() {return description;}
    double cost()  { return 0.20 + exceedCost; }
};
class Mocha:public Condiment
{
public:
    Mocha(Beverage *b){
        description = b->getDescription() + ", Mocha";
        exceedCost = b->cost();
        }
public:
    string getDescription() {return description;}
    double cost()  { return 0.30 + exceedCost; }
};
class Whip:public Condiment
{
public:
    Whip(Beverage *b){
        description = b->getDescription() + ", Whip";
        exceedCost = b->cost();
        }
public:
    string getDescription() {return description;}
    double cost()  { return 0.40 + exceedCost; }
};

 int main()
 {
     Beverage *houseHold = new HouseHold();
     houseHold = new Soy(houseHold);
     houseHold = new Mocha(houseHold);
     houseHold = new Whip(houseHold);
     printf("Welcome to Starbucks!\n");
     printf("your order is: ");
     cout << houseHold->getDescription() << endl;
     printf("HouseHold: %.2lf\n\n",houseHold->cost());

     Beverage *darkRoast = new DarkRoast();
     darkRoast = new Mocha(darkRoast);
     darkRoast = new Mocha(darkRoast);
     darkRoast = new Whip(darkRoast);
     printf("Welcome to Starbucks!\n");
     printf("your order is: ");
     cout << darkRoast->getDescription() << endl;
     printf("DarkRoast: %.2lf\n\n",darkRoast->cost());

     Beverage *espresso = new Espresso();
     printf("Welcome to Starbucks!\n");
     printf("your order is: ");
     cout << espresso->getDescription() << endl;
     printf("Espresso: %.2lf\n\n",espresso->cost());
}
/*
输出结果：
Welcome to Starbucks!
your order is: HouseHold , Soy, Mocha, Whip
HouseHold: 1.79

Welcome to Starbucks!
your order is: DarkRoast, Mocha, Mocha, Whip
DarkRoast: 2.99

Welcome to Starbucks!
your order is: Espresso
Espresso: 2.99
*/

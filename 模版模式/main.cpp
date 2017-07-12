#include "iostream"

using namespace std;

class CaffeineBeverage{
public:
    virtual void brew()=0;
    virtual void addCondiments()=0;

    void boilWater(){
        cout << "Boiling water" << endl;
    }

    void pourInCup(){
        cout << "Pouring into cup" << endl;
    }

    void prepareRecope(){
        boilWater();
        brew();
        pourInCup();
        addCondiments();
    }
};

class Tea:public CaffeineBeverage{
public:
    void brew(){
        cout << "Steeping the tea" << endl;
    }
    void addCondiments(){
        cout << "Adding Lemon" << endl;
    }
};

class Coffee:public CaffeineBeverage{
public:
    void brew(){
        cout << "Dripping Coffee through filter" << endl;
    }
    void addCondiments(){
        cout << "Adding Sugar and Milk" << endl;
    }
};

int main(){
    Tea myTea = Tea();
    myTea.prepareRecope();
}
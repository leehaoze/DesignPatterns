//leehaoze
#include <iostream>


using namespace std;

class Duck{
public:
    virtual void quack()=0;
    virtual void fly()=0;
};

class MallardDuck:public Duck{
public:
    void quack(){
        cout << "Quack" << endl;
    }
    void fly(){
        cout << "I am flying" << endl;
    }
};

class Turkey{
public:
    virtual void gobble()=0;
    virtual void fly()=0;
};

class WildTurkey:public Turkey{
public:
    void gobble(){
        cout << "Gooble gobble"<<endl;
    }
    void fly(){
        cout << "I am flying a shot distance " << endl;
    }
};

class TurkeyAdapter:public Duck{
private:
    Turkey* turkey_;
public:
    TurkeyAdapter(Turkey * turkey){
        turkey_ = turkey;
    }
    void quack(){
        turkey_->gobble();
    }
    void fly(){
        turkey_->fly();
        turkey_->fly();
        turkey_->fly();
        turkey_->fly();
        turkey_->fly();
    }
};

int main() {
    MallardDuck duck = MallardDuck();
    WildTurkey turkey = WildTurkey();
    TurkeyAdapter turkeyAdapter = TurkeyAdapter(&turkey);
    cout << "The Turkey says..." << endl;
    turkey.gobble();
    turkey.fly();

    cout << "The Duck says..." << endl;
    duck.quack();
    duck.fly();

    cout << "The TurkeyAdapter says..." << endl;
    turkeyAdapter.quack();
    turkeyAdapter.fly();
}
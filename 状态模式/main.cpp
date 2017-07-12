//leehaoze
#include <iostream>

using namespace std;


class State{
public:
    virtual void insertQuarter()=0;
    virtual void ejectQuarter()=0;
    virtual void turnCrank()=0;
    virtual void dispense()=0;
};

class GumballMachine;

class NoQuarterState:public State{
private:
    GumballMachine *gumballMachine_;
public:
    NoQuarterState(GumballMachine *gumballMachine):gumballMachine_(gumballMachine){}
    void insertQuarter();
    void ejectQuarter() {
        cout << "You haven't inserted a quarter" << endl;
    }

    void turnCrank() {
        cout << "You turned, but there\'s no quarter" << endl;
    }

    void dispense() {
        cout << "You need to pay first" << endl;
    }
};

class SoldOutState:public State{
private:
    GumballMachine *gumballMachine_;
public:
    SoldOutState(GumballMachine *gumballMachine):gumballMachine_(gumballMachine){}
    void insertQuarter(){}
    void ejectQuarter(){}
    void turnCrank(){}
    void dispense(){}
};

class HasQuarterState:public State{
private:
    GumballMachine *gumballMachine_;
public:
    HasQuarterState(GumballMachine *gumballMachine):gumballMachine_(gumballMachine){}
    void insertQuarter(){
        cout << "You can not insert another quarter" << endl;
    }
    void ejectQuarter() ;

    void turnCrank();

    void dispense() {
        cout << "No gumball dispendsed" << endl;
    }
};

class SoldState:public State{
private:
    GumballMachine *gumballMachine_;
public:
    SoldState(GumballMachine *gumballMachine):gumballMachine_(gumballMachine){}
    void insertQuarter(){
        cout << "Please wait, we are already giving you a gumball" << endl;
    }
    void ejectQuarter() {
        cout << "Sorry, you already turned the crank" << endl;
    }

    void turnCrank() {
        cout << "Turning twice doesn\'t get you another gumball!" << endl;
    }

    void dispense();

};

class GumballMachine{
private:
    SoldOutState soldOutState_;
    NoQuarterState noQuarterState_;
    HasQuarterState hasQuarterState_;
    SoldState soldState_;
    State* state_;
    int count_;
public:
    GumballMachine(int num):soldOutState_(SoldOutState(this)),noQuarterState_(NoQuarterState(this)),hasQuarterState_(HasQuarterState(this)),soldState_(SoldState(this)),count_(num){
        if(num > 0)
            state_ = &noQuarterState_;
        else
            state_ = &soldOutState_;
    }
    void insertQuarter(){
        state_->insertQuarter();
    }
    void ejectQuarter(){
        state_->ejectQuarter();
    }
    void turnCrank(){
        state_->turnCrank();
    }
    void setState(State &state){
        state_ = &state;
    }
    void releaseBall(){
        cout << "A gumball comes rolling out the slot..." << endl;
        if(count_ != 0)
            --count_;
    }
    State& getSoldOutState(){
        return soldOutState_;
    }
    State& getNoQuarterState(){
        return noQuarterState_;
    }
    State& getHasQuarterState(){
        return hasQuarterState_;
    }
    State& getSoldState(){
        return soldState_;
    }
    int getCount(){
        return count_;
    }
};

void NoQuarterState::insertQuarter(){
    cout << "You inserted a quarter" << endl;
    gumballMachine_->setState(gumballMachine_->getHasQuarterState());
}

void HasQuarterState::ejectQuarter() {
    cout << "Quarter returned" << endl;
    gumballMachine_->setState(gumballMachine_->getNoQuarterState());
}

void HasQuarterState::turnCrank() {
    cout << "You turned" << endl;
    gumballMachine_->setState(gumballMachine_->getSoldState());
}

void SoldState::dispense() {
    gumballMachine_->releaseBall();
    if(gumballMachine_->getCount() > 0){
        gumballMachine_->setState(gumballMachine_->getNoQuarterState());
    }
    else{
        cout << "Oops, out of gumballs!" << endl;
        gumballMachine_->setState(gumballMachine_->getSoldOutState());
    }
}

int main() {
    GumballMachine gumballMachine = GumballMachine(5);
    gumballMachine.ejectQuarter();
    gumballMachine.turnCrank();
}
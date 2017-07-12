#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*
父类:
FlyBehavior
子类:
FlyWithWings
FlyNoWay
FlyRocketPowered
*/
class FlyBehavior
{
public:
    virtual void fly() = 0;
};
class FlyWithWings:public FlyBehavior
{
public:
    void fly()
    {
        printf("I am flying.\n");
    }
};
class FlyNoWay:public FlyBehavior
{
public:
    void fly()
    {
        printf("I can not fly.\n");
    }
};
class FlyRocketPowered:public FlyBehavior
{
public:
    void fly() {
        printf("I am flying with a rocket.\n");
    }
};
//*****************************************************
/*
父类:
QuackBehavior
子类:
Quack
MuteQuack
Squeak
*/
class QuackBehavior
{
public:
    virtual void quack() = 0;
};
class Quack:public QuackBehavior
{
public:
    void quack()
    {
        printf("Quack\n");
    }
};

class MuteQuack:public QuackBehavior
{
public:
    void quack()
    {
        printf("<< Silence >>\n");
    }
};
class Squeak:public QuackBehavior
{
public:
    void quack()
    {
        printf("Squeak\n");
    }
};
//*****************************************************
/*
父类:
Duck
子类:
ModelDuck
MallardDuck
RedHeadDuck
RubberDuck
DecoyDuck
*/
class Duck
{
protected:
    FlyBehavior* flyBehavior_;
    QuackBehavior* quackBehavior_;
public:
    void swim()
    {
        printf("All ducks float, even decoys!\n");
    }
    void performQuack()
    {
        quackBehavior_->quack();
    }
    void performFly()
    {
        flyBehavior_->fly();
    }
    virtual void display() = 0;
public:
    void setFlyBehavior(FlyBehavior *f){
        flyBehavior_ = f;
    }
    void setQuackBehavior(QuackBehavior *q){
        quackBehavior_ = q;
    }
};

class ModelDuck: public Duck
{
public:
    ModelDuck() {
        flyBehavior_ = new FlyNoWay();
        quackBehavior_ = new Quack();
    }

    void display() {
        printf("I am a Model duck.\n");
    }
};

class MallardDuck: public Duck
{
public:
    MallardDuck() {
        flyBehavior_ = new FlyWithWings();
        quackBehavior_ = new Quack();
    }

    void display() {
        printf("I am a real Mallard duck.\n");
    }
};
class RedHeadDuck: public Duck
{
public:
    RedHeadDuck() {
        flyBehavior_ = new FlyWithWings();
        quackBehavior_ = new Quack();
    }

    void display() {
        printf("I am a RedHead duck.\n");
    }
};
class RubberDuck: public Duck
{
public:
    RubberDuck() {
        flyBehavior_ = new FlyNoWay();
        quackBehavior_ = new MuteQuack();
    }

    void display() {
        printf("I am Rubber duck.\n");
    }
};
class DecoyDuck: public Duck
{
public:
    DecoyDuck() {
        flyBehavior_ = new FlyNoWay();
        quackBehavior_ = new Squeak();
    }

    void display() {
        printf("I am a Decoy duck.\n");
    }
};
//*****************************************************

int main()
{
    //第一只鸭子
    Duck *mallord = new MallardDuck();
    mallord->display();
    mallord->performFly();
    mallord->setFlyBehavior(new FlyRocketPowered());
    mallord->performFly();

    printf("\n");

    //第二只鸭子
    Duck *rubberDuck = new RubberDuck();
    rubberDuck->display();
    rubberDuck->performQuack();
    rubberDuck->setQuackBehavior(new Squeak());
    rubberDuck->performQuack();
    return 0;
}
/*
I am a real Mallard duck.
I am flying.
I am flying with a rocket.

I am Rubber duck.
<< Silence >>
Squeak
*/
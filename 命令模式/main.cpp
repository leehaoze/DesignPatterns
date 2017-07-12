//leehaoze
#include <iostream>

using namespace std;


class Light{
private:
    string postion_;
public:
    Light(string postion):postion_(postion){}
    void on(){
        cout << postion_ + "\'s light is on" << endl;
    }
    void off(){
        cout << postion_ + "\'s light is off" << endl;
    }
};

class GarageDoor{
private:
    string postion_;
public:
    GarageDoor(string postion="House"):postion_(postion){}
    void up(){
        cout << postion_ + "\'s garage door was open" << endl;
    }
    void down(){
        cout << postion_ + "\'s garage door was closed" << endl;
    }
    void stop(){
        cout << postion_ + "\'s garage door was stopped" << endl;
    }
    void lightOn(){
        cout << postion_ + "\'s garage door\'s light was on" << endl;
    }
    void lightOff(){
        cout << postion_ + "\'s garage door\'s light was off" << endl;
    }
};

class Stereo{
private:
    string postion_;
public:
    Stereo(string postion):postion_(postion){}
    void on(){
        cout << postion_ + "\'s Stereo was on" << endl;
    }
    void off(){
        cout << postion_ + "\'s Stereo was off" << endl;
    }
    void setCD(){
        cout << postion_ + "\'s Stereo set CD success" << endl;
    }
    void setRadio(){
        cout << postion_ + "\'s Stereo set Radio success" << endl;
    }
    void setVolume(){
        cout << postion_ + "\'s Stereo set Volume success" << endl;
    }
};

class CeilingFan{
private:
    string postion_;
public:
    CeilingFan(string postion):postion_(postion){}

    void on(){
        cout << postion_ + "\'s Fan is on" << endl;
    }
    void off(){
        cout << postion_ + "\'s Fan is off" << endl;
    }
};


class Command{
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
};

class LightOnCommand:public Command{
private:
    Light light_;
public:
    LightOnCommand(Light light):light_(light){}
    void execute(){
        light_.on();
    }
    void undo(){
        light_.off();
    }
};

class LightOffCommand:public Command{
private:
    Light light_;
public:
    LightOffCommand(Light light):light_(light){}
    void execute(){
        light_.off();
    }
    void undo(){
        light_.on();
    }
};

class CeilingFanOnCommand:public Command{
private:
    CeilingFan fan_;
public:
    CeilingFanOnCommand(CeilingFan fan):fan_(fan){}
    void execute(){
        fan_.on();
    }
    void undo(){
        fan_.off();
    }
};

class CeilingFanOffCommand:public Command{
private:
    CeilingFan fan_;
public:
    CeilingFanOffCommand(CeilingFan fan):fan_(fan){}
    void execute(){
        fan_.off();
    }
    void undo(){
        fan_.on();
    }
};

class StereoOnWithCDCommand:public Command{
private:
    Stereo stereo_;
public:
    StereoOnWithCDCommand(Stereo stereo):stereo_(stereo){}
    void execute(){
        stereo_.on();
        stereo_.setCD();
        stereo_.setVolume();
    }
    void undo(){
        stereo_.off();
    }
};

class StereoOff:public Command{
private:
    Stereo stereo_;
public:
    StereoOff(Stereo stereo):stereo_(stereo){}
    void execute(){
        stereo_.off();
    }
    void undo(){
        stereo_.on();
        stereo_.setCD();
        stereo_.setVolume();
    }
};

class GarageDoorUpCommand:public Command{
private:
    GarageDoor garage_;
public:
    GarageDoorUpCommand(GarageDoor garage):garage_(garage){}
    void execute(){
        garage_.up();
    }
    void undo(){
        garage_.down();
    }
};

class GarageDoorDownCommand:public Command{
private:
    GarageDoor garage_;
public:
    GarageDoorDownCommand(GarageDoor garage):garage_(garage){}
    void execute(){
        garage_.down();
    }
    void undo(){
        garage_.up();
    }
};

class RemoteControl{
private:
    Command** onCommands;
    Command** offCommands;
    Command* undoCommand;
public:
    RemoteControl(){
        onCommands = new Command*[10];
        offCommands = new Command*[10];
    }
    void setCommand(int slot,Command &onCommand,Command &offCommand){
        onCommands[slot] = &onCommand;
        offCommands[slot] = &offCommand;
    }

    void onButtonWasPushed(int slot){
        onCommands[slot]->execute();
        undoCommand = onCommands[slot];
    }

    void offButtonWasPushed(int slot){
        offCommands[slot]->execute();
        undoCommand = offCommands[slot];
    }

    void undoButtonWasPushed(){
        undoCommand->undo();
        cout << "undo Command " << endl;
    }
};

int main() {
    RemoteControl remoteControl = RemoteControl();

    Light livingRoomLight = Light("Living Room");
    Light kitchenLight = Light("Kitchen");
    CeilingFan ceilingFan = CeilingFan("Living Room");
    GarageDoor garageDoor = GarageDoor();
    Stereo stereo = Stereo("Living Room");

    LightOnCommand livingRoomLightOn = LightOnCommand(livingRoomLight);
    LightOffCommand livingRoomLightOff = LightOffCommand(livingRoomLight);
    LightOnCommand kitchenLightOn = LightOnCommand(kitchenLight);
    LightOffCommand kitchenLightOff = LightOffCommand(kitchenLight);
    CeilingFanOnCommand ceilingFanOn = CeilingFanOnCommand(ceilingFan);
    CeilingFanOffCommand ceilingFanOff = CeilingFanOffCommand(ceilingFan);
    GarageDoorDownCommand garageDoorDown = GarageDoorDownCommand(garageDoor);
    StereoOnWithCDCommand stereoOnWithCD = StereoOnWithCDCommand(stereo);
    StereoOff stereoOff = StereoOff(stereo);

    remoteControl.setCommand(0, livingRoomLightOn, livingRoomLightOff);
    remoteControl.setCommand(1, kitchenLightOn, kitchenLightOff);
    remoteControl.setCommand(2, ceilingFanOn, ceilingFanOff);
    remoteControl.setCommand(3, stereoOnWithCD, stereoOff);


    remoteControl.onButtonWasPushed(0);
    remoteControl.offButtonWasPushed(0);
    remoteControl.onButtonWasPushed(1);
    remoteControl.offButtonWasPushed(1);
    remoteControl.onButtonWasPushed(2);
    remoteControl.offButtonWasPushed(2);
    remoteControl.onButtonWasPushed(3);
    remoteControl.offButtonWasPushed(3);

    remoteControl.onButtonWasPushed(0);
    remoteControl.undoButtonWasPushed();
    remoteControl.onButtonWasPushed(1);
    remoteControl.undoButtonWasPushed();
    remoteControl.onButtonWasPushed(2);
    remoteControl.undoButtonWasPushed();
    remoteControl.onButtonWasPushed(3);
    remoteControl.undoButtonWasPushed();
}
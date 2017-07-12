class Command(object):
    def execute(self):
        raise NotImplementedError

    def undo(self):
        raise NotImplementedError

class Light:
    def __init__(self, postion):
        self.postion = postion

    def on(self):
        print self.postion + '\'s light on'

    def off(self):
        print self.postion + '\'s light off'


class GarageDoor:
    def __init__(self, postion=None):
        self.postion = postion

    def up(self):
        if self.postion:
            print self.postion + '\'s garage door is open'
        else:
            print 'garage door is open'

    def down(self):
        if self.postion:
            print self.postion + '\'s garage door is cloased'
        else:
            print 'garage door is closed'

    def stop(self):
        if self.postion:
            print self.postion + '\'s garage door is stopped'
        else:
            print 'garage door is stopped'

    def lightOn(self):
        if self.postion:
            print self.postion + '\'s garage door\'s light is on'
        else:
            print 'garage door\'s light is on'

    def lightOff(self):
        if self.postion:
            print self.postion + '\'s garage door\'s light is off'
        else:
            print 'garage door\'s light is off'


class Stereo:
    def __init__(self, postion):
        self.postion = postion

    def on(self):
        print self.postion + '\'s ' + 'Stereo is on'

    def off(self):
        print self.postion + '\'s ' + 'Stereo is off'

    def setCd(self):
        print self.postion + '\'s ' + 'Stereo set CD success'

    def setDvd(self):
        print self.postion + '\'s ' + 'Stereo set DVD success'

    def setRadio(self):
        print self.postion + '\'s ' + 'Stereo set radio success'

    def setVolume(self):
        print self.postion + '\'s ' + 'Stereo set Volume success'


class CeilingFan:
    def __init__(self, postion):
        self.postion = postion

    def on(self):
        print self.postion + '\'s Fan is on'

    def off(self):
        print self.postion + '\'s Fan is off'


class LightOnCommand(Command):
    def __init__(self, light):
        self.light = light

    def execute(self):
        self.light.on()

    def undo(self):
        self.light.off()


class LightOffCommand(Command):
    def __init__(self, light):
        self.light = light

    def execute(self):
        self.light.off()

    def undo(self):
        self.light.off()


class CeilingFanOnCommand(Command):
    def __init__(self, fan):
        self.fan = fan

    def execute(self):
        self.fan.on()

    def undo(self):
        self.fan.off()


class CeilingFanOffCommand(Command):
    def __init__(self, fan):
        self.fan = fan

    def execute(self):
        self.fan.off()

    def undo(self):
        self.fan.on()


class StereoOnWithCDCommand(Command):
    def __init__(self, stereo):
        self.stereo = stereo

    def execute(self):
        self.stereo.on()
        self.stereo.setCd()
        self.stereo.setVolume()

    def undo(self):
        self.stereo.off()


class StereoOff(Command):
    def __init__(self, stereo):
        self.stereo = stereo

    def execute(self):
        self.stereo.off()

    def undo(self):
        self.stereo.on()
        self.stereo.setCd()
        self.stereo.setVolume()


class GarageDoorUpCommand(Command):
    def __init__(self, garage_door):
        self.garage_door = garage_door

    def execute(self):
        self.garage_door.up()

    def undo(self):
        self.garage_door.down()

class GarageDoorDownCommand(Command):
    def __init__(self, garage_door):
        self.garage_door = garage_door

    def execute(self):
        self.garage_door.down()

    def undo(self):
        self.garage_door.on()


class RemoteControl:
    def __init__(self):
        self.onCommands = {}
        self.offCommands = {}
        self.undoCommand = None

    def __str__(self):
        string = "----- Remote Control -----\n"
        command_num = self.onCommands.__len__()
        for each in range(0, command_num):
            string += 'slot[' + str(each) + '] ' + str(self.onCommands[each].__dict__) + '    ' + str(self.offCommands[
                each].__dict__) + '\n'
        return string

    def setCommand(self, slot, onCommand, offCommand):
        self.onCommands[slot] = onCommand
        self.offCommands[slot] = offCommand

    def onButtonWasPushed(self, slot):
        self.onCommands[slot].execute()
        self.undoCommand = self.onCommands[slot]

    def offButtonWasPushed(self, slot):
        self.offCommands[slot].execute()
        self.undoCommand = self.offCommands[slot]

    def undoButtonWasPushed(self):
        self.undoCommand.undo()
        print 'undo Command ' + str(self.undoCommand.__dict__)

remoteControl = RemoteControl()

livingRoomLight = Light('Living Room')
kitchenLight = Light('Kitchen')
ceilingFan = CeilingFan('Living Room')
garageDoor = GarageDoor()
stereo = Stereo('Living Room')

livingRoomLightOn = LightOnCommand(livingRoomLight)
livingRoomLightOff = LightOffCommand(livingRoomLight)
kitchenLightOn = LightOnCommand(kitchenLight)
kitchenLightOff = LightOffCommand(kitchenLight)
ceilingFanOn = CeilingFanOnCommand(ceilingFan)
ceilingFanOff = CeilingFanOffCommand(ceilingFan)
garageDoorDown = GarageDoorDownCommand(garageDoor)
stereoOnWithCD = StereoOnWithCDCommand(stereo)
stereoOff = StereoOff(stereo)

remoteControl.setCommand(0, livingRoomLightOn, livingRoomLightOff)
remoteControl.setCommand(1, kitchenLightOn, kitchenLightOff)
remoteControl.setCommand(2, ceilingFanOn, ceilingFanOff)
remoteControl.setCommand(3, stereoOnWithCD, stereoOff)

print remoteControl

remoteControl.onButtonWasPushed(0)
remoteControl.offButtonWasPushed(0)
remoteControl.onButtonWasPushed(1)
remoteControl.offButtonWasPushed(1)
remoteControl.onButtonWasPushed(2)
remoteControl.offButtonWasPushed(2)
remoteControl.onButtonWasPushed(3)
remoteControl.offButtonWasPushed(3)

print '----- undo test ------'
remoteControl.onButtonWasPushed(0)
remoteControl.undoButtonWasPushed()
remoteControl.onButtonWasPushed(1)
remoteControl.undoButtonWasPushed()
remoteControl.onButtonWasPushed(2)
remoteControl.undoButtonWasPushed()
remoteControl.onButtonWasPushed(3)
remoteControl.undoButtonWasPushed()
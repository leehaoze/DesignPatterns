class State:
    def insertQuarter(self):
        raise NotImplementedError

    def ejectQuarter(self):
        raise NotImplementedError

    def turnCrank(self):
        raise NotImplementedError

    def dispense(self):
        raise NotImplementedError


class NoQuarterState(State):
    def __init__(self, gumballMachine):
        self.gumballMachine = gumballMachine

    def insertQuarter(self):
        print "You inserted a quarter"
        self.gumballMachine.setState(self.gumballMachine.getHasQuarterState())

    def ejectQuarter(self):
        print "You haven't inserted a quarter"

    def turnCrank(self):
        print "You turned, but there\'s no quarter"

    def dispense(self):
        print "You need to pay first"


class SoldOutState(State):
    def __init__(self, gumballMachine):
        self.gumballMachine = gumballMachine



class HasQuarterState(State):
    def __init__(self, gumballMachine):
        self.gumballMachine = gumballMachine

    def insertQuarter(self):
        print "You can not insert another quarter"

    def ejectQuarter(self):
        print "Quarter returned"
        self.gumballMachine.setState(self.gumballMachine.getNoQuarterState())

    def turnCrank(self):
        print "You turned"
        self.gumballMachine.setState(self.gumballMachine.getSoldState())

    def dispense(self):
        print "No gumball dispendsed"


class SoldState(State):
    def __init__(self, gumballMachine):
        self.gumballMachine = gumballMachine

    def insertQuarter(self):
        print "Please wait, we are already giving you a gumball"

    def ejectQuarter(self):
        print "Sorry, you already turned the crank"

    def turnCrank(self):
        print "Turning twice doesn\'t get you another gumball!"

    def dispense(self):
        self.gumballMachine.releaseBall()
        if self.gumballMachine.getCount() > 0:
            self.gumballMachine.setState(self.gumballMachine.getNoQuarterState())
        else:
            print "Oops, out of gumballs!"
            self.gumballMachine.setState(self.gumballMachine.getSoldOutState())


class GumballMachine:
    def __init__(self, numberGumballs):
        self.soldOutState, self.noQuarterState, self.hasQuarterState, self.soldState = SoldOutState(
            self.__class__), NoQuarterState(self.__class__), HasQuarterState(self.__class__), SoldState(self.__class__)
        if numberGumballs > 0:
            self.state = self.noQuarterState
        else:
            self.state = self.soldOutState
        self.count = numberGumballs

    def insertQuarter(self):
        self.state.insertQuarter()

    def ejectQuarter(self):
        self.state.ejectQuarter()

    def turnCrank(self):
        self.state.turnCrank()

    def setState(self, state):
        self.state = state

    def releaseBall(self):
        print "A gumball comes rolling out the slot..."
        if self.count is not 0:
            self.count = self.count - 1

    def getSoldOutState(self):
        return self.soldOutState

    def getNoQuarterState(self):
        return self.noQuarterState

    def getHasQuarterState(self):
        return self.hasQuarterState

    def getSoldState(self):
        return self.soldState

    def getCount(self):
        return self.count


gumballMachine = GumballMachine(5)
gumballMachine.ejectQuarter()
gumballMachine.turnCrank()

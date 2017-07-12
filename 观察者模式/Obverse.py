# -*- coding:UTF-8 -*-

class Subject:
    def registerObserver(self, o):
        raise NotImplementedError

    def removeObserver(self, o):
        raise NotImplementedError

    def notifyObservers(self):
        raise NotImplementedError


class Observer:
    def update(self, temp, humidity, pressure):
        raise NotImplementedError


class DisplayElement:
    def display(self):
        raise NotImplementedError


class WeatherData(Subject):
    observers = []
    temperature, humidity, pressure = None, None, None

    def registerObserver(self, o):
        self.observers.append(o)

    def removeObserver(self, o):
        self.observers.remove(o)

    def notifyObservers(self):
        for each in self.observers:
            each.update(self.temperature, self.humidity, self.pressure)

    def measurementsChanged(self):
        self.notifyObservers()

    def setMeasurements(self, temperature, humidity, pressure):
        self.temperature, humidity, pressure = temperature, humidity, pressure
        self.measurementsChanged()


class CurrentConditionsDisplay(Observer, DisplayElement):
    temperature, humidity, weatherData = None, None, None

    def __init__(self, weatherData):
        self.weatherData = weatherData
        self.weatherData.registerObserver(self)

    def display(self):
        print 'Current conditions: ' + str(self.temperature) + "F degrees and " + str(self.humidity) + "% humidity"

    def update(self, temperature, humidity, pressure):
        self.temperature, humidity = temperature, humidity
        self.display()


weatherData = WeatherData()
currentDisplay = CurrentConditionsDisplay(weatherData)
weatherData.setMeasurements(80, 65, 30.4)
weatherData.setMeasurements(82, 70, 29.2)
weatherData.setMeasurements(78, 90, 29.2)

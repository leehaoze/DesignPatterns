#include <vector>
#include "iostream"

using namespace std;

class Observer {
public:
    virtual void update(int temp, int humidity, double pressure)=0;
};

class Subject {
public:

    virtual void registerObserver(Observer &o)=0;

    virtual void removeObserver(Observer &o)=0;

    virtual void notifyObservers()=0;
};

class DisplayElemnet {
public:
    virtual void display()=0;
};

class WeatherData : public Subject {
private:
    vector<Observer *> observers;
    int temperature, humidity;
    double pressure;
public:
    WeatherData(){}

    void registerObserver(Observer &o) {
        observers.push_back(&o);
    }

    void removeObserver(Observer &o) {
    }

    void notifyObservers() {
        for (int i = 0; i < observers.size(); ++i) {
            observers[i]->update(temperature, humidity, pressure);
        }
    }

    void measurementsChange() {
        notifyObservers();
    }

    void setMeasurements(int temperature, int humidity, double pressure) {
        this->temperature = temperature;
        this->pressure = pressure;
        this->humidity = humidity;
        measurementsChange();
    }
};

class CurrentConditionsDisplay : public Observer, DisplayElemnet {
private:
    int temperature_, humidity_;
    WeatherData *weatherData_;
public:
    CurrentConditionsDisplay(WeatherData *weatherData) : weatherData_(weatherData) {
        weatherData_->registerObserver(*this);
    }

    void display() {
        cout << "Current conditions: " << temperature_ << "F degrees and " << humidity_ << "% humidity" << endl;
    }

    void update(int temp, int humi, double press) {
        temperature_ = temp;
        humidity_ = humi;
        display();
    }
};

int main() {
    WeatherData weatherData = WeatherData();
    CurrentConditionsDisplay currentConditionsDisplay = CurrentConditionsDisplay(&weatherData);
    weatherData.setMeasurements(80, 65, 30.4);
    weatherData.setMeasurements(82, 70, 29.2);
    weatherData.setMeasurements(78, 90, 29.2);
}

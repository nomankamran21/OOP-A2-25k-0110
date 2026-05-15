#include "Car.h"


Car::Car()
    : Vehicle(), doors(4), transmission("Manual"), fuelType("Petrol"),
      color("White"), condition("Used"), TIRE_COUNT(4) {}


Car::Car(const string& a, const string& b, int c, double d, int e,
         const CarFeatures& f, int g, const string& h,
         const string& i, const string& j, const string& k)
    : Vehicle(a, b, c, d, e, f),
      doors(g), transmission(h), fuelType(i),
      color(j), condition(k), TIRE_COUNT(4) {}


Car::Car(const Car& c)
    : Vehicle(c), doors(c.doors), transmission(c.transmission),
      fuelType(c.fuelType), color(c.color), condition(c.condition),
      TIRE_COUNT(4) {}


Car& Car::operator=(const Car& c) {
    if (this != &c) {
        Vehicle::operator=(c);
        doors        = c.doors;
        transmission = c.transmission;
        fuelType     = c.fuelType;
        color        = c.color;
        condition    = c.condition;
        
    }
    return *this;
}


int    Car::getDoors()        const { return doors; }
string Car::getTransmission() const { return transmission; }
string Car::getFuelType()     const { return fuelType; }
string Car::getColor()        const { return color; }
string Car::getCondition()    const { return condition; }
int    Car::getTireCount()    const { return TIRE_COUNT; }


void Car::setDoors(int a)                  { doors = a; }
void Car::setTransmission(const string& a) { transmission = a; }
void Car::setFuelType(const string& a)     { fuelType = a; }
void Car::setColor(const string& a)        { color = a; }
void Car::setCondition(const string& a)    { condition = a; }

string Car::getVehicleType() const { return "Car"; }


void Car::displayInfo() const {
    Vehicle::displayInfo();
    cout << doors << " " << transmission << " " << fuelType << " " << color << " " << condition << "\n";
}

bool Car::isAutomatic() const {
    return transmission == "Automatic";
}

bool Car::isEcoFriendly() const {
    return fuelType == "Hybrid" || fuelType == "Electric";
}

double Car::estimateResaleValue() const {
    double val = price;
    for (int i = 0; i < getAge(); i++) val *= 0.90;
    return val;
}

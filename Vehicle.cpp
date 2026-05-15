#include "Vehicle.h"

int Vehicle::vehicleCounter = 0;


Vehicle::Vehicle()
    : vehicleID(++vehicleCounter), brand(""), model(""),
      year(2020), price(0.0), mileage(0) {}
Vehicle::Vehicle(const string& br, const string& mo, int yr,
                 double pr, int mil, const CarFeatures& feat)
    : vehicleID(++vehicleCounter), brand(br), model(mo),
      year(yr), price(pr), mileage(mil), features(feat) {}


Vehicle::Vehicle(const Vehicle& v)
    : vehicleID(++vehicleCounter), brand(v.brand), model(v.model),
      year(v.year), price(v.price), mileage(v.mileage), features(v.features) {}

Vehicle::~Vehicle() {}

int         Vehicle::getVehicleID() const { return vehicleID; }
string      Vehicle::getBrand()     const { return brand; }
string      Vehicle::getModel()     const { return model; }
int         Vehicle::getYear()      const { return year; }
double      Vehicle::getPrice()     const { return price; }
int         Vehicle::getMileage()   const { return mileage; }
CarFeatures& Vehicle::getFeatures()       { return features; }

void Vehicle::setBrand(const string& b)        { brand = b; }
void Vehicle::setModel(const string& m)        { model = m; }
void Vehicle::setPrice(double p)               { price = p; }
void Vehicle::setMileage(int m)                { mileage = m; }
void Vehicle::setFeatures(const CarFeatures& f){ features = f; }

int Vehicle::getVehicleCounter() { return vehicleCounter; }

int Vehicle::getAge() const {
    return 2024 - year;
}

bool Vehicle::isValidYear() const {
    return year >= MIN_YEAR && year <= 2025;
}

void Vehicle::displayInfo() const {
    cout << vehicleID << " " << year << " " << brand << " " << model << " " << price << " " << mileage << "\n";
    features.display();
}

void Vehicle::applyDiscount(double pct) {
    if (pct > 0 && pct <= 100) {
        if (year < 2015) {
            price -= (price * (pct / 100.0) * 1.5);
        } else {
            price -= (price * (pct / 100.0));
        }
        price = (int)price;
        cout << "[Vehicle] " << pct << "% discount applied. New price: Rs " << price << "\n";
    }
}

// Requirement 5: Friend function implementation to compare prices
bool isMoreExpensive(const Vehicle& v1, const Vehicle& v2) {
    return v1.price > v2.price;
}



#include "Bike.h"
#include <iomanip>   /

Bike::Bike() : Vehicle(), engineCC(0), bikeType("Generic"), hasSelfStart(false) {}

Bike::Bike(const string& br, const string& mo, int yr, double pr, int mil,
           const CarFeatures& feat, int cc, const string& type, bool self)
    : Vehicle(br, mo, yr, pr, mil, feat), engineCC(cc), bikeType(type), hasSelfStart(self) {}

string Bike::getVehicleType() const {
    return "Bike";
}

void Bike::displayInfo() const {
    cout << "------------------------------------------\n";
    cout << " BIKE DETAILS (ID: " << vehicleID << ")\n";
    cout << "------------------------------------------\n";
    cout << " Brand: " << brand << " | Model: " << model << " (" << year << ")\n";
    cout << " Price: Rs " << fixed << setprecision(2) << price << "\n";
    cout << " Mileage: " << mileage << " km\n";
    cout << " Engine: " << engineCC << " CC\n";
    cout << " Type: " << bikeType << "\n";
    cout << " Self Start: " << (hasSelfStart ? "Yes" : "No") << "\n";
    
    
}

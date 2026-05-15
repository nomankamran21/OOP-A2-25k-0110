#ifndef BIKE_H
#define BIKE_H

#include "Vehicle.h"

// Bike class inherits from Vehicle (Requirement 1)
class Bike : public Vehicle {
private:
    int engineCC;
    string bikeType; 
    bool hasSelfStart;

public:
    Bike();
    Bike(const string& br, const string& mo, int yr, double pr, int mil,
         const CarFeatures& feat, int cc, const string& type, bool self);

    // Polymorphism: overriding virtual functions (Requirement 2)
    string getVehicleType() const override;
    void displayInfo() const override;
    Vehicle* clone() const override { return new Bike(*this); }// copying done  dynamically to better strngthen my concepts

    int getCC() const { return engineCC; } 
    void setCC(int cc) { engineCC = cc; }
};


#endif

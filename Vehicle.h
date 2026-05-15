#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>
#include "CarFeatures.h"
using namespace std;

// ═══════════════════════════════════════════════════════════════
//  CLASS 5: Vehicle  
//  • COMPOSITION: with CarFeatures 
//  • static vehicleCounter: 
//  • const MIN_YEAR / MAX_MILEAGE: 
// ═══════════════════════════════════════════════════════════════
#include "IDisplayable.h"
#include "IBaseEntity.h"

class Vehicle : public IDisplayable, public IBaseEntity {
protected:
    int         vehicleID;
    string      brand;
    string      model;
    int         year;
    double      price;
    int         mileage;
    CarFeatures features;       

    static int vehicleCounter;

    
    static const int MIN_YEAR    = 1980;
    static const int MAX_MILEAGE = 500000;

public:
    
    Vehicle();

    Vehicle(const string& br, const string& mo, int yr,
            double pr, int mil, const CarFeatures& feat);

    
    Vehicle(const Vehicle& v);

    virtual ~Vehicle();

    int         getVehicleID() const;
    string      getBrand()     const;
    string      getModel()     const;
    int         getYear()      const;
    double      getPrice()     const;
    int         getMileage()   const;
    CarFeatures& getFeatures();

    void setBrand(const string& b);
    void setModel(const string& m);
    void setPrice(double p);
    void setMileage(int m);
    void setFeatures(const CarFeatures& f);

    static int getVehicleCounter();

    
    int getID() const override { return vehicleID; }
    string getEntityType() const override { return "Vehicle"; }
    void display() const override { displayInfo(); }

    int  getAge()       const;  
    bool isValidYear()  const;   

    virtual void   displayInfo()     const;
    void           applyDiscount(double pct);

    // This makes the class abstract (Requirement 3)
    virtual string getVehicleType()  const = 0;
    virtual Vehicle* clone()         const = 0; 

    // Operator overloading to compare vehicle IDs (Requirement 4)
    bool operator==(const Vehicle& other) const {
        return this->vehicleID == other.vehicleID;
    }

    // Overloading + to combine prices for a total (Requirement 4)
    double operator+(const Vehicle& other) const {
        return this->price + other.price;
    }

    // Friend function to compare prices, accessing private price members (Requirement 5)
    friend bool isMoreExpensive(const Vehicle& v1, const Vehicle& v2);

    // Friend function to check affordability (Requirement 5)
    friend bool canBuyerAfford(const class Buyer& b, const Vehicle& v);    // i personally think that for these types of cases making friend functions are better
                                                                         // instead of inheriting a new class or comp or aggration  because these  they are straight forward and simple
};



#endif

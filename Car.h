#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

class Car : public Vehicle {
private:
    int    doors;
    string transmission;   
    string fuelType;       
    string color;
    string condition;      

    const int TIRE_COUNT;  

public:
    Car();

    Car(const string& a, const string& b, int c, double d, int e,
        const CarFeatures& f, int g, const string& h,
        const string& i, const string& j, const string& k);

    Car(const Car& c);

    Car& operator=(const Car& c);  

    int    getDoors()        const;
    string getTransmission() const;
    string getFuelType()     const;
    string getColor()        const;
    string getCondition()    const;
    int    getTireCount()    const;

    void setDoors(int a);
    void setTransmission(const string& a);
    void setFuelType(const string& a);
    void setColor(const string& a);
    void setCondition(const string& a);

    string getVehicleType() const override;
    Vehicle* clone() const override { return new Car(*this); }

    void   displayInfo()            const override;
    bool   isAutomatic()            const;
    bool   isEcoFriendly()          const;
    double estimateResaleValue()    const;
};

#endif

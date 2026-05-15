#ifndef CARFEATURES_H
#define CARFEATURES_H

#include <iostream>
using namespace std;

// ═══════════════════════════════════════════════════════════════
//  CLASS 4: CarFeatures
//  COMPOSITION inside Vehicle 
// ═══════════════════════════════════════════════════════════════
class CarFeatures {
private:
    bool hasAC;
    bool hasSunroof;
    bool hasNavigation;
    bool hasLeatherSeats;
    bool hasBackupCamera;

public:
    
    CarFeatures();


    CarFeatures(bool ac, bool sunroof, bool nav, bool leather, bool cam);


    CarFeatures(const CarFeatures& f);

    
    bool getHasAC()           const;
    bool getHasSunroof()      const;
    bool getHasNavigation()   const;
    bool getHasLeatherSeats() const;
    bool getHasBackupCamera() const;

    
    void setHasAC(bool v);
    void setHasSunroof(bool v);
    void setHasNavigation(bool v);
    void setHasLeatherSeats(bool v);
    void setHasBackupCamera(bool v);

    
    void display()        const;
    int  countFeatures()  const;
    bool isPremium()      const;
    void enableAll();
};

#endif

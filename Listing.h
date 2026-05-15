#ifndef LISTING_H
#define LISTING_H

#include <iostream>
#include <string>
#include "Vehicle.h"
#include "Car.h"
#include "Bike.h"
#include "User.h"

class Listing {
private:
    int      listingID;
    Vehicle* vehicle;           // Changed from Car to Vehicle* for polymorphism
    User*    seller;            
    string   description;
    string   postedDate;
    bool     isApproved;
    bool     isActive;


    static int listingCounter;
    static const int MAX_PHOTOS = 10;  

public:
    
    Listing();

    
    Listing(const Vehicle& v, User* sel, const string& desc, const string& date);

    
    Listing(const Listing& l);

    
    ~Listing();

    
    Listing& operator=(const Listing& l); // compares different listings

    int        getListingID()   const;
    Vehicle*   getVehicle()     const;
    User*      getSeller()      const;
    string     getDescription() const;
    string     getPostedDate()  const;
    bool       getIsApproved()  const;
    bool       getIsActive()    const;

    void setDescription(const string& d);
    void setApproved(bool a);
    void setActive(bool a);
    void setSeller(User* s);

    static int getListingCounter();

    bool matchesBrand(const string& br)                          const;
    bool matchesFilter(const string& brand, double minPrice,
                       double maxPrice, int minYear, int maxYear) const;

    void display()          const;
    void approveListing();
    void deactivate();

};

#endif


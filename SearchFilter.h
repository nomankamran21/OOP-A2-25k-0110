#ifndef SEARCHFILTER_H
#define SEARCHFILTER_H

#include <iostream>
#include <string>
#include "Listing.h"
using namespace std;

// ═══════════════════════════════════════════════════════════════
//  CLASS 11: SearchFilter
//  Encapsulates all search/filter criteria in one place.
// ═══════════════════════════════════════════════════════════════
class SearchFilter {
private:
    string brand;
    string model;
    double minPrice;
    double maxPrice;
    int    minYear;
    int    maxYear;
    int    maxMileage;
    string transmission;

    
    const string* const defaultBrand;

public:
   
    SearchFilter();

   
    SearchFilter(const string& br, double minP, double maxP,
                 int minY, int maxY, int maxMil);

   
    ~SearchFilter();

    
    void setBrand(const string& b);
    void setModel(const string& m);
    void setPriceRange(double mn, double mx);
    void setYearRange(int mn, int mx);
    void setMaxMileage(int m);
    void setTransmission(const string& t);

    
    string getBrand()      const;
    string getModel()      const;
    double getMinPrice()   const;
    double getMaxPrice()   const;
    int    getMinYear()    const;
    int    getMaxYear()    const;
    int    getMaxMileage() const;

    
    void display()                   const;
    bool matches(const Listing& lst) const;
    void reset();
    bool isDefault()                 const;
};

#endif

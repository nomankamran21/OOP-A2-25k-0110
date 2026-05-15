#ifndef ADDRESS_H
#define ADDRESS_H

#include <iostream>
#include <string>
using namespace std;

// ═══════════════════════════════════════════════════════════════
//  CLASS 1: Address
//  Value object used by COMPOSITION inside User.
//  Address cannot exist without a User.
// ═══════════════════════════════════════════════════════════════
class Address {
private:
    string province,city,street,postalCode,country;
    

public:
    
    Address();

    
    Address(const string& st, const string& ci, const string& pr,
            const string& co, const string& pc);

    
    Address(const Address& obj1);

    
    void setStreet(const string& s);
    void setCity(const string& c);
    void setProvince(const string& p);
    void setCountry(const string& c);
    void setPostalCode(const string& p);

    string getStreet()     const;
    string getCity()       const;
    string getProvince()   const;
    string getCountry()    const;
    string getPostalCode() const;

    
    void   display()                        const;
    bool   isSameCity(const Address& other) const;
    void   updateCity(const string& newCity);
    string getFullAddress()                 const;
};

#endif

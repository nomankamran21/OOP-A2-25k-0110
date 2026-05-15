#include "Address.h"


Address::Address()
    : street(""), city(""), province(""), country("Pakistan"), postalCode("") {}

Address::Address(const string& st, const string& ci, const string& pr,
                 const string& co, const string& pc)
    : street(st), city(ci), province(pr), country(co), postalCode(pc) {}


Address::Address(const Address& other)
    : street(other.street), city(other.city), province(other.province),
      country(other.country), postalCode(other.postalCode) {}

void Address::setStreet(const string& s)    { street = s; }
void Address::setCity(const string& c)      { city = c; }
void Address::setProvince(const string& p)  { province = p; }
void Address::setCountry(const string& c)   { country = c; }
void Address::setPostalCode(const string& p){ postalCode = p; }

string Address::getStreet()     const { return street; }
string Address::getCity()       const { return city; }
string Address::getProvince()   const { return province; }
string Address::getCountry()    const { return country; }
string Address::getPostalCode() const { return postalCode; }


void Address::display() const {
    cout << street << ", " << city << ", " << province
         << ", " << country << " - " << postalCode;
}

bool Address::isSameCity(const Address& other) const {
    return city == other.city;
}

void Address::updateCity(const string& newCity) {
    city = newCity;
    cout << "[Address] City updated to: " << newCity << "\n";
}

string Address::getFullAddress() const {
    return street + ", " + city + ", " + province + ", " + country;
}

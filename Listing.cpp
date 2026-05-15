#include "Listing.h"

int Listing::listingCounter = 0;


Listing::Listing()
    : listingID(++listingCounter), vehicle(nullptr), seller(nullptr),
      description(""), postedDate(""), isApproved(false), isActive(false) {}

 
Listing::Listing(const Vehicle& v, User* sel, const string& desc, const string& date)
    : listingID(++listingCounter), seller(sel),
      description(desc), postedDate(date), isApproved(false), isActive(true) {
    vehicle = v.clone(); 
}


Listing::Listing(const Listing& l)
    : listingID(l.listingID), seller(l.seller),
      description(l.description), postedDate(l.postedDate),
      isApproved(l.isApproved), isActive(l.isActive) {
    if (l.vehicle) {
        vehicle = l.vehicle->clone();
    } else {
        vehicle = nullptr;
    }
}


Listing::~Listing() {
    if (vehicle) delete vehicle;
}


Listing& Listing::operator=(const Listing& l) {
    if (this != &l) {
        if (vehicle) delete vehicle;
        
        if (l.vehicle) {
            vehicle = l.vehicle->clone();
        } else {
            vehicle = nullptr;
        }
        
        listingID   = l.listingID;  
        seller      = l.seller;     
        description = l.description;
        postedDate  = l.postedDate;
        isApproved  = l.isApproved;
        isActive    = l.isActive;
    }
    return *this;
}



int        Listing::getListingID()   const { return listingID; }
Vehicle*   Listing::getVehicle()     const { return vehicle; }
User*      Listing::getSeller()      const { return seller; }
string     Listing::getDescription() const { return description; }
string     Listing::getPostedDate()  const { return postedDate; }
bool       Listing::getIsApproved()  const { return isApproved; }
bool       Listing::getIsActive()    const { return isActive; }


void Listing::setDescription(const string& d) { description = d; }
void Listing::setApproved(bool a)             { isApproved = a; }
void Listing::setActive(bool a)               { isActive = a; }
void Listing::setSeller(User* s)              { seller = s; }

int Listing::getListingCounter() { return listingCounter; }

bool Listing::matchesBrand(const string& br) const {
    if (!vehicle) return false;
    return vehicle->getBrand() == br;
}

bool Listing::matchesFilter(const string& brand, double minPrice,
                             double maxPrice, int minYear, int maxYear) const {
    if (!isApproved || !isActive || !vehicle) return false;
    if (!brand.empty() && vehicle->getBrand() != brand) return false;
    if (vehicle->getPrice() < minPrice || vehicle->getPrice() > maxPrice) return false;
    if (vehicle->getYear()  < minYear  || vehicle->getYear()  > maxYear)  return false;
    return true;
}


void Listing::display() const {
    cout << "┌─ Listing #" << listingID
         << " [" << (isApproved ? "APPROVED" : "PENDING") << "]"
         << " [" << (isActive   ? "ACTIVE"   : "INACTIVE") << "] ─\n";
    if (vehicle) {
        vehicle->displayInfo();
    } else {
        cout << "  [No Vehicle Info]\n";
    }
    cout << "  Description: " << description << "\n";
    cout << "  Posted: " << postedDate << "\n";
    if (seller) cout << "  Seller: " << seller->getName() << "\n";
    cout << "└──────────────────────────────\n";
}

void Listing::approveListing() {
    isApproved = true;
    cout << "[Listing #" << listingID << "] Approved!\n";
}

void Listing::deactivate() {
    isActive = false;
    cout << "[Listing #" << listingID << "] Deactivated.\n";
}

#include "Seller.h"
#include "Admin.h"

Seller::Seller()
    : User(), listingCount(0), shopName(""), rating(0.0), totalSales(0) {}

Seller::Seller(const string& n, const string& em, const string& ph,
               const string& pwd, const Address& addr, const string& shop)
    : User(n, em, ph, pwd, addr),
      listingCount(0), shopName(shop), rating(0.0), totalSales(0) {}

Seller::Seller(const Seller& s)
    : User(s), listingCount(s.listingCount), shopName(s.shopName),
      rating(s.rating), totalSales(s.totalSales) {
    for (int i = 0; i < listingCount; i++)
        myListingIDs[i] = s.myListingIDs[i];
}

string Seller::getUserType() const { return "Seller"; }

string Seller::getShopName()    const { return shopName; }
double Seller::getRating()      const { return rating; }
int    Seller::getTotalSales()  const { return totalSales; }
int    Seller::getListingCount()const { return listingCount; }

void Seller::setShopName(const string& s) { shopName = s; }
void Seller::setRating(double r)          { if (r >= 0 && r <= 5) rating = r; }

void Seller::addListingID(int id) {
    if (listingCount < 50) {
        myListingIDs[listingCount++] = id;
        cout << "[Seller:" << name << "] Listing #" << id << " added.\n";
    }
}

bool Seller::removeListingID(int id) {
    for (int i = 0; i < listingCount; i++) {
        if (myListingIDs[i] == id) {
            for (int j = i; j < listingCount - 1; j++)
                myListingIDs[j] = myListingIDs[j + 1];
            --listingCount;
            cout << "[Seller] Listing #" << id << " removed.\n";
            return true;
        }
    }
    return false;
}

void Seller::incrementSales() {
    ++totalSales;
    cout << "[Seller:" << name << "] Total sales: " << totalSales << "\n";
}

bool Seller::isTrustedSeller() const {
    return rating >= 4.0 && totalSales >= 5;
}

void Seller::displayProfile() const {
    User::displayProfile();
    cout << "Role  : Seller | Shop: " << shopName
         << " | Rating: " << rating << "/5"
         << " | Sales: "  << totalSales
         << " | Active Listings: " << listingCount << "\n";
}

bool isSellerVerified(const Seller& s, const Admin& a) {
    return (a.getAdminLevel() != "Junior") && !s.shopName.empty();
}

#ifndef SELLER_H
#define SELLER_H

#include "User.h"

// ═══════════════════════════════════════════════════════════════
//  CLASS 9: Seller  (Derived from User)
//  • Array: myListingIDs[50] — tracks IDs of this seller's listings
// ═══════════════════════════════════════════════════════════════
class Seller : public User {
private:
    int    myListingIDs[50];   
    int    listingCount;
    string shopName;
    double rating;             
    int    totalSales;

public:
   
    Seller();

   
    Seller(const string& n, const string& em, const string& ph,
           const string& pwd, const Address& addr, const string& shop);

   
    Seller(const Seller& s);

    string getUserType() const override;

    string getShopName()    const;
    double getRating()      const;
    int    getTotalSales()  const;
    int    getListingCount()const;

    void setShopName(const string& s);
    void setRating(double r);

    void addListingID(int id);
    bool removeListingID(int id);
    void incrementSales();
    bool isTrustedSeller() const;

    void displayProfile() const override;

    // Requirement 5: Friend function to verify seller through admin data
    friend bool isSellerVerified(const class Seller& s, const class Admin& a);
};


#endif

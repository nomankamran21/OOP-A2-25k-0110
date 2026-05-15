#ifndef BUYER_H
#define BUYER_H

#include "User.h"
#include "Message.h"

// ═══════════════════════════════════════════════════════════════
//  CLASS 8: Buyer  (Derived from User)
//  • ARRAY OF OBJECTS: inbox[50] — stores Message objects directly
//  • ARRAY: favorites[20] — stores listing IDs of saved listings
// ═══════════════════════════════════════════════════════════════
class Buyer : public User {
private:
    int     favorites[20];  
    int     favCount;
    Message inbox[50];       
    int     inboxCount;
    string  membershipLevel;
    double  budget;

public:

    Buyer();

    
    Buyer(const string& n, const string& em, const string& ph,
          const string& pwd, const Address& addr, double bud);

    
    Buyer(const Buyer& b);

    string getUserType() const override;

    int    getFavCount()        const;
    int    getInboxCount()      const;
    double getBudget()          const;
    string getMembershipLevel() const;

    void setBudget(double b);
    void setMembershipLevel(const string& m);

    void saveFavorite(int listingID);
    bool removeFavorite(int listingID);
    void receiveMessage(const Message& msg);
    void displayFavorites() const;
    void displayInbox()     const;

    void displayProfile() const override;

    // Requirement 5: Friend function to check if buyer can afford a vehicle
    friend bool canBuyerAfford(const class Buyer& b, const class Vehicle& v);
};


#endif

#ifndef MARKETPLACE_H
#define MARKETPLACE_H

#include <iostream>
#include <string>
#include "Listing.h"
#include "Message.h"
#include "Buyer.h"
#include "Seller.h"
#include "Admin.h"
#include "SearchFilter.h"
using namespace std;

// ═══════════════════════════════════════════════════════════════
//  CLASS 12: Marketplace  (Main Controller/page or hub)
//  • ARRAY OF OBJECTS: listings[100], messages[200]
//  • static totalListingsCreated, totalMessagesCreated:
//  • const PLATFORM_NAME — the marketplace name never changes.
// ═══════════════════════════════════════════════════════════════
class Marketplace {
private:
    Listing  listings[100];    
    Message  messages[200];    
    int      listingCount;
    int      messageCount;
    string   version;

    
    const string PLATFORM_NAME;

    /
    static int totalListingsCreated;
    static int totalMessagesCreated;

public:
   
    Marketplace(const string& name, const string& ver);

    static int getTotalListingsCreated();
    static int getTotalMessagesCreated();

    int  addListing(const Vehicle& vehicle, User* seller,
                    const string& desc, const string& date);

    bool updateListingDescription(int listingID, const string& newDesc);
    bool deleteListing(int listingID, Admin& admin);
    bool approveListing(int listingID, Admin& admin);

    // Operator overloading to add a listing to the marketplace (Requirement 4)
    Marketplace& operator+(const Listing& lst) {
        if (listingCount < 100) {
            listings[listingCount++] = lst;
            cout << "[Marketplace] Listing added via '+' operator!\n";
        } else {
            cout << "[Marketplace] Error: Storage full!\n";
        }
        return *this;
    }

    void searchListings(const SearchFilter& filter)  const;
    void listAllApprovedListings()                   const;

    void sendMessage(Buyer& buyer, Seller& seller,
                     const string& content, const string& ts);
    void displayAllMessages() const;

    void displayStats() const;

};

#endif

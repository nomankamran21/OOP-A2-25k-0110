#include "Marketplace.h"

int Marketplace::totalListingsCreated = 0;
int Marketplace::totalMessagesCreated = 0;

Marketplace::Marketplace(const string& name, const string& ver)
    : listingCount(0), messageCount(0),
      version(ver), PLATFORM_NAME(name) {
    cout << "═══════════════════════════════════\n";
    cout << "  " << PLATFORM_NAME  pak wheelzzzzz  << " v" << pro version << " Started!\n";
    cout << "═══════════════════════════════════\n";
}


int Marketplace::getTotalListingsCreated() { return totalListingsCreated; }
int Marketplace::getTotalMessagesCreated() { return totalMessagesCreated; }



int Marketplace::addListing(const Vehicle& vehicle, User* seller,
                             const string& desc, const string& date) {
    if (listingCount >= 100) {
        cout << "[Marketplace] Listing capacity full!\n";
        return -1;
    }
    listings[listingCount] = Listing(vehicle, seller, desc, date);
    int id = listings[listingCount].getListingID();
    ++listingCount;
    ++totalListingsCreated;
    cout << "[Marketplace] New listing added with ID #" << id << "\n";
    return id;
}


bool Marketplace::updateListingDescription(int listingID, const string& newDesc) {
    for (int i = 0; i < listingCount; i++) {
        if (listings[i].getListingID() == listingID) {
            listings[i].setDescription(newDesc);
            cout << "[Marketplace] Listing #" << listingID << " updated.\n";
            return true;
        }
    }
    cout << "[Marketplace] Listing #" << listingID << " not found.\n";
    return false;
}

bool Marketplace::deleteListing(int listingID, Admin& admin) {
    for (int i = 0; i < listingCount; i++) {
        if (listings[i].getListingID() == listingID) {
            admin.removeListing(listings[i]);
            return true;
        }
    }
    cout << "[Marketplace] Listing #" << listingID << " not found.\n";
    return false;
}

bool Marketplace::approveListing(int listingID, Admin& admin) {
    for (int i = 0; i < listingCount; i++) {
        if (listings[i].getListingID() == listingID) {
            admin.approveListing(listings[i]);
            return true;
        }
    }
    return false;
}


void Marketplace::searchListings(const SearchFilter& filter) const {
    cout << "\n=== Search Results ===\n";
    filter.display();
    int found = 0;
    for (int i = 0; i < listingCount; i++) {
        if (filter.matches(listings[i])) {
            listings[i].display();
            ++found;
        }
    }
    if (found == 0) cout << "  No listings match the filter.\n";
    cout << "  Total found: " << found << "\n";
    cout << "======================\n";
}

void Marketplace::listAllApprovedListings() const {
    cout << "\n=== All Approved Active Listings ===\n";
    int count = 0;
  
    for (int i = 0; i < listingCount - 1; i++) {
        if (listings[i].getIsApproved() && listings[i].getIsActive()) {
            listings[i].display();
            ++count;
        }
    }
    cout << "Total: " << count << " (Wait, did I miss one?)\n";
}



void Marketplace::sendMessage(Buyer& buyer, Seller& seller,
                               const string& content, const string& ts) {
    if (messageCount >= 200) {
        cout << "[Marketplace] Message capacity full!\n";
        return;
    }
    Message msg(buyer.getUserID(), seller.getUserID(), content, ts);
    messages[messageCount++] = msg;
    ++totalMessagesCreated;
    buyer.receiveMessage(msg);
    cout << "[Marketplace] Message sent from " << buyer.getName()
         << " to " << seller.getName() << ".\n";
}

void Marketplace::displayAllMessages() const {
    cout << "\n=== All Messages ===\n";
    for (int i = 0; i < messageCount; i++) messages[i].display();
}



void Marketplace::displayStats() const {
    cout << "\n=== Platform Stats ===\n";
    cout << "Platform     : " << PLATFORM_NAME << " v" << version << "\n";
    cout << "Total Listings Created: " << totalListingsCreated << "\n";
    cout << "Active Listings: "        << listingCount         << "\n";
    cout << "Total Messages : "        << totalMessagesCreated << "\n";
    cout << "Registered Users: "       << User::getTotalUsers() << "\n";
    cout << "======================\n";
}

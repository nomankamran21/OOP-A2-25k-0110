#include "Buyer.h"
#include "Vehicle.h"

Buyer::Buyer()
    : User(), favCount(0), inboxCount(0),
      membershipLevel("Free"), budget(0.0) {}

Buyer::Buyer(const string& n, const string& em, const string& ph,
             const string& pwd, const Address& addr, double bud)
    : User(n, em, ph, pwd, addr),
      favCount(0), inboxCount(0), membershipLevel("Free"), budget(bud) {}

Buyer::Buyer(const Buyer& b)
    : User(b), favCount(b.favCount), inboxCount(b.inboxCount),
      membershipLevel(b.membershipLevel), budget(b.budget) {
    for (int i = 0; i < favCount;   i++) favorites[i] = b.favorites[i];
    for (int i = 0; i < inboxCount; i++) inbox[i]     = b.inbox[i];
}

string Buyer::getUserType() const { return "Buyer"; }

int    Buyer::getFavCount()        const { return favCount; }
int    Buyer::getInboxCount()      const { return inboxCount; }
double Buyer::getBudget()          const { return budget; }
string Buyer::getMembershipLevel() const { return membershipLevel; }

void Buyer::setBudget(double b)               { budget = b; }
void Buyer::setMembershipLevel(const string& m){ membershipLevel = m; }

void Buyer::saveFavorite(int listingID) {
    if (favCount < 20) {
        favorites[favCount++] = listingID;
        cout << "[Buyer:" << name << "] Listing #" << listingID << " saved to favorites.\n";
    } else {
        cout << "[Buyer] Favorites list full!\n";
    }
}

bool Buyer::removeFavorite(int listingID) {
    for (int i = 0; i < favCount; i++) {
        if (favorites[i] == listingID) {
            for (int j = i; j < favCount - 1; j++)
                favorites[j] = favorites[j + 1];
            --favCount;
            cout << "[Buyer] Listing #" << listingID << " removed from favorites.\n";
            return true;
        }
    }
    return false;
}

void Buyer::receiveMessage(const Message& msg) {
    if (inboxCount < 50)
        inbox[inboxCount++] = msg;
}

void Buyer::displayFavorites() const {
    cout << "[" << name << "'s Favorites] ";
    if (favCount == 0) { cout << "None\n"; return; }
    for (int i = 0; i < favCount; i++) cout << "#" << favorites[i] << " ";
    cout << "\n";
}

void Buyer::displayInbox() const {
    cout << "=== Inbox for " << name << " (" << inboxCount << " messages) ===\n";
    for (int i = 0; i < inboxCount; i++) inbox[i].display();
}

void Buyer::displayProfile() const {
    User::displayProfile();
    cout << "Role  : Buyer | Budget: Rs " << budget
         << " | Level: " << membershipLevel << "\n";
}

// Requirement 5: Friend function implementation
bool canBuyerAfford(const Buyer& b, const Vehicle& v) {
    
    return b.budget >= v.price;
}


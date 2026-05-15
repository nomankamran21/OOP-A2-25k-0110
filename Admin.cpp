#include "Admin.h"


Admin::Admin()
    : User(), adminLevel("Junior"), approvedCount(0),
      removedCount(0), department("Moderation"), canBanUsers(false) {}


// BaningUsers is derived from level — only "Super" admins can ban
Admin::Admin(const string& n, const string& em, const string& ph,
             const string& pwd, const Address& addr,
             const string& lvl, const string& dept)
    : User(n, em, ph, pwd, addr),
      adminLevel(lvl), approvedCount(0), removedCount(0),
      department(dept), canBanUsers(lvl == "Super") {}

string Admin::getUserType() const { return "Admin"; }


string Admin::getAdminLevel()    const { return adminLevel; }
int    Admin::getApprovedCount() const { return approvedCount; }
int    Admin::getRemovedCount()  const { return removedCount; }


void Admin::approveListing(Listing& lst) {
    lst.approveListing();
    ++approvedCount;
}

void Admin::removeListing(Listing& lst) {
    lst.deactivate();
    ++removedCount;
    cout << "[Admin:" << name << "] Listing removed. Total removed: " << removedCount << "\n";
}

void Admin::banUser(User& u) {
    if (canBanUsers) {
        cout << "[Admin:" << name << "] User '" << u.getName() << "' banned.\n";
    } else {
        cout << "[Admin] Insufficient privileges to ban users.\n";
    }
}

void Admin::generateReport() const {
    cout << "=== Admin Report [" << name << "] ===\n";
    cout << "  Approved Listings : " << approvedCount << "\n";
    cout << "  Removed Listings  : " << removedCount  << "\n";
    cout << "  Admin Level       : " << adminLevel    << "\n";
}

void Admin::displayProfile() const {
    User::displayProfile();
    cout << "Role  : Admin | Level: " << adminLevel
         << " | Dept: "     << department
         << " | Approved: " << approvedCount
         << " | Removed: "  << removedCount << "\n";
}

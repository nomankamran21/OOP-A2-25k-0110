#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include "Listing.h"

// ═══════════════════════════════════════════════════════════════
//  CLASS 10: Admin  (Derived from User)
//  Admin can approve/remove listings and ban users.
//  only  "Super" level admins can ban users.
// ═══════════════════════════════════════════════════════════════
class Admin : public User {
private:
    string adminLevel;     
    int    approvedCount;
    int    removedCount;
    string department;
    bool   canBanUsers;    

public:
    
    Admin();

    
    Admin(const string& n, const string& em, const string& ph,
          const string& pwd, const Address& addr,
          const string& lvl, const string& dept);

    string getUserType() const override;

    string getAdminLevel()    const;
    int    getApprovedCount() const;
    int    getRemovedCount()  const;

    void approveListing(Listing& lst);
    void removeListing(Listing& lst);
    void banUser(User& u);
    void generateReport() const;

    void displayProfile() const override;

    // Requirement 5: Friend function to verify that sellers  are legit or cappers (Requirement 5)
    friend bool isSellerVerified(const class Seller& s, const Admin& a);
};



#endif

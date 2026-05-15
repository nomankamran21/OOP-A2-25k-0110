#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include "Address.h"
using namespace std;

// ═══════════════════════════════════════════════════════════════
//  CLASS 2: User  (Abstract Base Class)
//  • COMPOSITION: with Address 
//  • static members: totalUsers, nextUserID 
// ═══════════════════════════════════════════════════════════════
#include "IDisplayable.h"
#include "IBaseEntity.h"

class User : public IDisplayable, public IBaseEntity {
protected:
    int     userID;
    string  name;
    string  email;
    string  phone;
    string  passwordHash;
    Address address;          

    static int totalUsers;    
    static int nextUserID;    

public:
    
    User();

    
    User(const string& n, const string& em, const string& ph,
         const string& pwd, const Address& addr);

    
    User(const User& other);

    virtual ~User();

    int    getUserID()  const;
    string getName()    const;
    string getEmail()   const;
    string getPhone()   const;

    void setName(const string& n);
    void setEmail(const string& e);
    void setPhone(const string& p);
    void setAddress(const Address& a);

    static int getTotalUsers();
    static int getNextUserID();

    // These fulfill the IBaseEntity and IDisplayable abstract requirement
    int getID() const override { return userID; }
    string getEntityType() const override { return "User"; }
    void display() const override { displayProfile(); }

    virtual void   displayProfile() const;
    bool           verifyPassword(const string& pwd) const;
    void           updatePhone(const string& newPhone);

    // This makes the class abstract (Requirement 3)
    virtual string getUserType() const = 0;

    // Overloading == to compare users by email (Requirement 4)
    bool operator==(const User& other) const {
        return this->email == other.email;
    }

    // Friend function to check locations, (Requirement 5)
    friend bool areInSameCity(const User& u1, const User& u2);

};


#endif

#include "User.h"


int User::totalUsers = 0;
int User::nextUserID = 0;


User::User()
    : userID(++nextUserID), name(""), email(""), phone(""), passwordHash("") {
    ++totalUsers;
}


User::User(const string& n, const string& em, const string& ph,
           const string& pwd, const Address& addr)
    : userID(++nextUserID), name(n), email(em), phone(ph),
      passwordHash(pwd), address(addr) {
    ++totalUsers;
}


User::User(const User& other)
    : userID(++nextUserID), name(other.name), email(other.email),
      phone(other.phone), passwordHash(other.passwordHash),
      address(other.address) {
    ++totalUsers;
}

User::~User() { --totalUsers; }

int    User::getUserID()  const { return userID; }
string User::getName()    const { return name; }
string User::getEmail()   const { return email; }
string User::getPhone()   const { return phone; }

void User::setName(const string& n)    { name = n; }
void User::setEmail(const string& e)   { email = e; }
void User::setPhone(const string& p)   { phone = p; }
void User::setAddress(const Address& a){ address = a; }

int User::getTotalUsers() { return totalUsers; }
int User::getNextUserID() { return nextUserID; }

void User::displayProfile() const {
    cout << "──────────────────────────────\n";
    cout << "ID   : " << userID << "\n";
    cout << "Name : " << name   << "\n";
    cout << "Email: " << email  << "\n";
    cout << "Phone: " << phone  << "\n";
    cout << "Addr : "; address.display(); cout << "\n";
}

bool User::verifyPassword(const string& pwd) const {
    return passwordHash == pwd;
}

void User::updatePhone(const string& newPhone) {
    phone = newPhone;
    cout << "[User] Phone updated.\n";
}

// Requirement 5: Friend function to compare locations better as a insta feature or snap feature 
bool areInSameCity(const User& u1, const User& u2) {
    return u1.address.getCity() == u2.address.getCity();
}



#include "Marketplace.cpp"
#include "Address.cpp"
#include "Admin.cpp"
#include "Buyer.cpp"
#include "Car.cpp"
#include "Bike.cpp"  // Added Bike
#include "CarFeatures.cpp"
#include "Listing.cpp"
#include "Message.cpp"
#include "SearchFilter.cpp"
#include "Seller.cpp"
#include "User.cpp"
#include "Vehicle.cpp"

int main() {
    cout << "\n";
    cout << "================================================\n";
    cout << "   OOP ASSIGNMENT 02 - updated  MARKETPLACE   gaari ki deals only on  pak wheels pro max version     \n";
    cout << "================================================\n\n";

    
    Marketplace market("PakWheels Pro", "2.0");

    ─────────────────────────────────────────
    Address addr1("Gulshan", "Karachi", "Sindh", "Pakistan", "75300");
    Address addr2("DHA", "Karachi", "Sindh", "Pakistan", "75500");
    Address addr3("Model Town", "Lahore", "Punjab", "Pakistan", "54000");

    // i used dynamic memory aloocation cause virtual inheritence
    Seller* seller1 = new Seller("Noman Ahmed", "noman@example.com", "0333-1234567", "pass123", addr1, "Noman Motors");
    Buyer* buyer1 = new Buyer("Sara Khan", "sara@pw.com", "0301-2222222", "sara123", addr2, 5000000.0);
    Admin admin1("Admin Zain", "zain@admin.com", "0302-3333333", "admin123", addr3, "Senior", "Moderation");

    // ── Friend Function  working
    cout << "-- Friend Function: areInSameCity --\n";
    if (areInSameCity(*seller1, *buyer1)) {
        cout << " [OK] Seller and Buyer are in the same city! (Local deals possible)\n";
    } else {
        cout << " [INFO] Seller and Buyer are in different cities.\n";
    }
    cout << endl;

    CarFeatures luxuryFeat(true, true, true, true, true);
    
    
    Vehicle* v1 = new Car("Toyota", "Camry", 2021, 8500000, 15000, luxuryFeat, 4, "Automatic", "Hybrid", "Silver", "New");
    Vehicle* v2 = new Bike("Honda", "CBR", 2023, 1200000, 2000, luxuryFeat, 600, "Sports", true);
    Vehicle* v3 = new Bike("Yamaha", "YBR", 2014, 150000, 45000, luxuryFeat, 125, "Commuter", false);

    cout << "-- Vehicle Info (Polymorphism) --\n";
    v1->displayInfo();
    v2->displayInfo();
    v3->displayInfo();

    // ── Operator Overloading  example
    cout << "\n-- Operator Overloading: == (Users) --\n";
    if (*seller1 == *buyer1) {
        cout << " Same email? Something is wrong!\n";
    } else {
        cout << " Users are unique (different emails).\n";
    }

    // ── Operator Overloading  2 nd example
    cout << "\n-- Operator Overloading: + (Marketplace) --\n";
    Listing l1(*v1, seller1, "Excellent Hybrid Sedan", "2026-05-10");
    Listing l2(*v2, seller1, "Fast sports bike", "2026-05-10");
    Listing l3(*v3, seller1, "Old but gold", "2026-05-10");


    market + l1; // Using overloaded +
    market + l2;
    market + l3;

    // ── Friend Function 
    cout << "\n-- Friend Function: isMoreExpensive --\n";
    if (isMoreExpensive(*v1, *v2)) {
        cout << " " << v1->getBrand() << " is more expensive than " << v2->getBrand() << "\n";
    }

    // New Friend Functions for Assignment 2   to verif that is the seller legit
    cout << "\n-- Friend Function: isSellerVerified --\n";
    if (isSellerVerified(*seller1, admin1)) {
        cout << " Seller " << seller1->getName() << " is verified by admin.\n";
    }

    cout << "\n-- Friend Function: canBuyerAfford --\n";
    if (canBuyerAfford(*buyer1, *v2)) {
        cout << " Buyer " << buyer1->getName() << " can afford the " << v2->getBrand() << ".\n";
    } else {
        cout << " Buyer cannot afford the " << v2->getBrand() << ".\n";
    }


    
    cout << "\n--  applyDiscount   --\n";
    cout << "Original Price of YBR: Rs " << v3->getPrice() << "\n";
    v3->applyDiscount(10); // 10% discount
    // If it's < 2015, it applies 1.5x discount (15%) and casts to int.
    cout << "New Price: Rs " << v3->getPrice() << "\n";

    
    cout << "\n-listAllApprovedListings --\n";
    market.approveListing(l1.getListingID(), admin1);
    market.approveListing(l2.getListingID(), admin1);
    market.approveListing(l3.getListingID(), admin1); 
    
    market.listAllApprovedListings();

    //  deleting all the dynamic objects is important  to ensure that no memory leaks occur
    delete seller1;
    delete buyer1;
    delete v1;
    delete v2;
    delete v3;

    cout << "\n═══ Program Ended  goodbye from suneel munjj═══\n";
    return 0;
}


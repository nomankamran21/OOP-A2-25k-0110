# OOP-Assignment-2
# 🚗 OOP Assignment 02: PakWheels Pro Max Marketplace

Welcome to the **PakWheels Pro Max** Marketplace! This project is an advanced Object-Oriented Programming (OOP) assignment built in C++, focusing on a vehicle marketplace system. 

![Marketplace Overview]<img width="860" height="424" alt="Screenshot 2026-05-15 163712" src="https://github.com/user-attachments/assets/c87c2b4b-5809-467a-9216-b3d8e2098f8d" />


## 📌 Project Overview
This project builds upon Assignment 1, introducing advanced OOP concepts like Inheritance, Polymorphism, Abstraction, Operator Overloading, and Friend Functions. The platform allows Buyers and Sellers to interact, list vehicles (Cars and Bikes), and process transactions.

---

## 🛠️ Key OOP Concepts Implemented

### 1. Inheritance
We've extended base classes to create specific, specialized entities:
- **`User` Hierarchy:** Extended into `Buyer`, `Seller`, and `Admin`. This creates a hierarchy where common account data like name and email are shared, while specific roles have unique features (e.g., Buyer has a budget, Seller has a shop name).
- **`Vehicle` Hierarchy:** Extended into `Car` and `Bike`. This demonstrates vehicle types inheriting core transport data like brand and price but adding specific details like engine size for bikes or number of doors for cars.

**Code Snippet:**
```cpp
// Instantiating derived classes (Dynamic Memory Allocation for Virtual Inheritance)
Seller* seller1 = new Seller("Noman Ahmed", "noman@example.com", "0333-1234567", "pass123", addr1, "Noman Motors");
Buyer* buyer1 = new Buyer("Sara Khan", "sara@pw.com", "0301-2222222", "sara123", addr2, 5000000.0);

Vehicle* v1 = new Car("Toyota", "Camry", 2021, 8500000, 15000, luxuryFeat, 4, "Automatic", "Hybrid", "Silver", "New");
Vehicle* v2 = new Bike("Honda", "CBR", 2023, 1200000, 2000, luxuryFeat, 600, "Sports", true);
```

![Vehicle Data]<img width="730" height="795" alt="Screenshot 2026-05-15 163917" src="https://github.com/user-attachments/assets/3bec1e9d-f88d-402e-be7d-db56aab77b1d" />


### 2. Polymorphism
Virtual functions ensure that the correct method is called for an object, regardless of the pointer type.
- `virtual void displayInfo()` is overridden in `Car`, `Bike`, `Buyer`, etc. When called on a `Vehicle` pointer, it correctly invokes the specific class's version depending on the object at runtime.

**Code Snippet:**
```cpp
cout << "-- Vehicle Info (Polymorphism) --\n";
v1->displayInfo(); // Automatically calls Car's displayInfo
v2->displayInfo(); // Automatically calls Bike's displayInfo
```

### 3. Abstraction
Abstract base classes and pure virtual interfaces force structure across the application:
- `IDisplayable`: A pure interface that forces any class to implement a `display()` method.
- `IBaseEntity`: A pure interface requiring a `getID()` method.
- `User` & `Vehicle` Classes: These act as templates and cannot be instantiated directly.

### 4. Operator Overloading
Custom operators provide intuitive interactions between objects:
- `==` to check if a user is already registered (by email) or to compare two vehicles by ID.
- `+` to seamlessly add a `Listing` directly to the `Marketplace` array, or to combine prices of two vehicles.

**Code Snippet:**
```cpp
Marketplace market("PakWheels Pro", "2.0");
Listing l1(*v1, seller1, "Excellent Hybrid Sedan", "2026-05-10");

// Overloaded + operator adds listing cleanly
market + l1; 
```

### 5. Friend Functions
Friend functions allow controlled, external access to private class members for specific relational operations:
- `areInSameCity(User, User)`: Accesses private addresses to see if users are local.
- `isMoreExpensive(Vehicle, Vehicle)`: Accesses protected price data.
- `isSellerVerified(Seller, Admin)`: Validates trust level.
- `canBuyerAfford(Buyer, Vehicle)`: Compares a buyer's private budget against a vehicle's private price.

**Code Snippet:**
```cpp
cout << "\n-- Friend Function: canBuyerAfford --\n";
if (canBuyerAfford(*buyer1, *v2)) {
    cout << " Buyer " << buyer1->getName() << " can afford the " << v2->getBrand() << ".\n";
}
```

![Output Results]<img width="921" height="905" alt="image" src="https://github.com/user-attachments/assets/ba058d84-f3b7-48d9-90f8-d09e5a66c0e9" />


---

## 🚀 Memory Management
Dynamic memory allocation (`new` and `delete`) handles the varied behavior of `Vehicle` pointers in the `Marketplace`. To ensure no memory leaks occur, deep/shallow copying is managed properly within the `Listing` class, and all dynamic instances are explicitly deleted at the end.

```cpp
delete seller1;
delete buyer1;
delete v1;
delete v2;
delete v3;
```

> *“Program Ended. Goodbye from Suneel Munj!”*

#ifndef IDISPLAYABLE_H
#define IDISPLAYABLE_H

// This is just a simple display for things that can show details
// I added this to fulfill the abstract class requirement
class IDisplayable {
public:
    
    virtual void display() const = 0;
    
   
    virtual ~IDisplayable() {}
};

#endif

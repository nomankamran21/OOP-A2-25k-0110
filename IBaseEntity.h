#ifndef IBASEENTITY_H
#define IBASEENTITY_H

#include <string>
using namespace std;

// Base class for everything that has an ID
// Another abstract class for the marks
class IBaseEntity {
public:
    virtual int getID() const = 0;
    virtual string getEntityType() const = 0;
    virtual ~IBaseEntity() {}
};

#endif

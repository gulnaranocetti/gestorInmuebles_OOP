#ifndef ICOLLECTION_H
#define ICOLLECTION_H

#include "ICollectible.h"
#include "IIterator.h"

class ICollection {
public:
    virtual void add(ICollectible* item) = 0;
    virtual void remove(ICollectible* item) = 0;
    virtual bool isEmpty() const = 0;
    virtual bool member(ICollectible* item) const = 0;
    virtual IIterator* getIterator() const = 0;
    virtual ~ICollection() {}
};

#endif

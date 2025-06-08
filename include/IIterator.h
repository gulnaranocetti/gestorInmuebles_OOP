#ifndef IITERATOR_H
#define IITERATOR_H

#include "ICollectible.h"

class IIterator {
public:
    virtual bool hasCurrent() const = 0;
    virtual ICollectible* getCurrent() const = 0;
    virtual void next() = 0;
    virtual ~IIterator() {}
};

#endif

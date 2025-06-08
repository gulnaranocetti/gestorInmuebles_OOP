// SetIterator.h
#ifndef SETITERATOR_H
#define SETITERATOR_H

#include <set>
#include "IIterator.h"

class SetIterator : public IIterator {
private:
    std::set<ICollectible*>::const_iterator actual;
    std::set<ICollectible*>::const_iterator fin;

public:
    SetIterator(const std::set<ICollectible*>& elementos)
        : actual(elementos.begin()), fin(elementos.end()) {}

    bool hasCurrent() const override {
        return actual != fin;
    }

    ICollectible* getCurrent() const override {
        return *actual;
    }

    void next() override {
        if (hasCurrent()) ++actual;
    }

    ~SetIterator() override {}
};

#endif

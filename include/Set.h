// Set.h
#ifndef SET_H
#define SET_H

#include <set>
#include "ICollection.h"
#include "SetIterator.h"

class Set : public ICollection {
private:
    std::set<ICollectible*> elementos;

public:
    void add(ICollectible* item) override {
        elementos.insert(item);
    }

    void remove(ICollectible* item) override {
        auto it = elementos.find(item);
        if (it != elementos.end()) {
            delete *it; 
            elementos.erase(it); 
        }
    }

    bool member(ICollectible* item) const override {
        return elementos.find(item) != elementos.end();
    }

    bool isEmpty() const override {
        return elementos.empty();
    }

    IIterator* getIterator() const override {
        return new SetIterator(elementos);
    }

    ~Set() override {
        for (auto e : elementos)
            delete e;
    }
};

#endif

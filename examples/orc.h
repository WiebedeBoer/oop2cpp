// orc.h

#ifndef ORC_H
#define ORC_H

#include "creature.h"

class Orc : public Creature
{
public:
    Orc(int health = 120);
    virtual void Greet() const;
};

#endif // ORC_H


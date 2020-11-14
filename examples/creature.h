// creature.h

#ifndef CREATURE_H
#define CREATURE_H

class Creature  //abstract class
{
public:
    Creature(int health = 100);
    virtual void Greet() const = 0;   //pure virtual member function
    virtual void DisplayHealth() const;

protected:
    int m_Health;
};

#endif // CREATURE_H


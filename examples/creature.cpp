// creature.cpp

#include "creature.h"

#include <iostream>

using namespace std;

Creature::Creature(int health): 
    m_Health(health)
{}

void Creature::DisplayHealth() const
{
    cout << "Health: " << m_Health << endl;
}


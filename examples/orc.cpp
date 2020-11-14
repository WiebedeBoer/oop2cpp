// orc.cpp

#include "orc.h"

#include <iostream>

using namespace std;

Orc::Orc(int health): 
    Creature(health)
{}

void Orc::Greet() const
{
    cout << "The orc grunts hello.\n";
}


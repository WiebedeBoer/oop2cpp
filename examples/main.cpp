// main.cpp
// Compile with: g++ main.cpp creature.cpp orc.cpp -o abstract_creature

#include "creature.h"
#include "orc.h"

#include <iostream>
using namespace std;

int main()
{
    Creature* pCreature = new Orc();
    pCreature->Greet();
    pCreature->DisplayHealth();
    
    return 0;
}

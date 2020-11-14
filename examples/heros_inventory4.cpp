// heros_inventory4.cpp
// Compile with: g++ -std=c++11 heros_inventory4.cpp -o heros_inventory4

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> inventory;
    inventory.push_back("sword");
    inventory.push_back("armor");
    inventory.push_back("shield");

	// traditional method
    for (vector<string>::iterator iter = inventory.begin(); iter != inventory.end(); ++iter)
    {
        cout << *iter << endl;
    }

	// using auto
	for (auto iter = inventory.begin(); iter != inventory.end(); ++iter)
    {
        cout << *iter << endl;
    }

	// using for each
	for (string s: inventory)
    {
        cout << s << endl;
    }

	// using for each with auto
	for (auto s: inventory)
    {
        cout << s << endl;
    }

    return 0;
}

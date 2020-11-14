// play_again.cpp
// Compile with: g++ play_again.cpp -o play_again

#include <iostream>
using namespace std;

int main() 
{
    char again = 'y';
    while (again == 'y')
    {
        cout << "\n**Played an exciting game**";
        cout << "\nDo you want to play again? (y/n): ";
        cin >> again;
    }

    cout << "\nOkay, bye." << endl;

    return 0;
}

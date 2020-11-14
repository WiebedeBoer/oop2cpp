// play_again2.cpp
// Compile with: g++ play_again2.cpp -o play_again2

#include <iostream>
using namespace std;

int main() 
{
    char again;
    do 
    {
        cout << "\n**Played an exciting game**";
        cout << "\nDo you want to play again? (y/n): ";
        cin >> again;
    } while (again == 'y');

    cout << "\nOkay, bye." << endl;

    return 0;
}

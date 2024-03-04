#include <iostream>
#include "RPG.h"

using namespace std;

int main() 
{    
    RPG person1;
    RPG person2("Mark", 100, 50, 50, "mage");

    cout << "\nPerson 1 is alive: " << person1.isAlive() << endl;
    cout << "\nPerson 2 is alive: " << person2.isAlive() << endl;

    person1.updateHealth(person1.getHealth() + 50);
    cout << "\nPerson 1 health: " << person1.getHealth() << endl;

    person2.updateHealth(person2.getHealth() + 40);
    cout << "\nPerson 2 health: " << person2.getHealth() << endl;

    return 0;
}

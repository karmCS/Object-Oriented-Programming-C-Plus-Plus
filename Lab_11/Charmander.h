#include <string>
#include <vector>
#include "Pokemon.h"
using namespace std;

class Charmander : public Pokemon{
    public:
        // Constructors
        Charmander();
        Charmander(string name, int hp, int att, int def, vector<string> t, vector<string> s);
        // Mutator functions
        void speak();
        void printStats();
    private:
    vector<string> skills;
    // name, hp, attack, defense
};

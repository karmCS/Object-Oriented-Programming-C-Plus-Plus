#ifndef RPG_H
# define RPG_H

#include <string>
using namespace std;

const int SKILL_SIZE = 2;

class RPG {
    public:
    //constructors
    RPG();
    RPG(string name, int health, int strength, int defense, string type);
    void setSkills();
    void printAction(string, RPG);
    void updateHealth(int);
    // void attack(RPG*);
    void useSkill(RPG*);
    bool isAlive();
    string getName();
    int getHealth();
    int getStrength();
    int getDefense();

    private:
    string name;
    int health;
    int strength;
    int defense;
    string type; // warrior, mage, theif, archer
    string skills[SKILL_SIZE];

};
#endif
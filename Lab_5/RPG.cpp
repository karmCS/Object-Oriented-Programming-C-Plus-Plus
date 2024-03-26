#include "RPG.h"
#include <iostream>

RPG::RPG()
{
    name = "NPC";
    health = 100;
    strength = 10;
    defense = 10;
    type = "warrior";
    skills[0] = "slash";
    skills[1] = "parry";
}

RPG::RPG(string name, int health, int strength, int defense, string type)
{
    this->name = name;
    this->health = health;
    this->strength = strength;
    this->defense = defense;
    this->type = type;
}

string RPG::getName()
{
    return name;
}

int RPG::getHealth()
{
    return health;
}

int RPG::getStrength()
{
    return strength;
}

int RPG::getDefense()
{
    return defense;
}


/**
 * @brief sets the skills based on the RPG's roles
 * 
*/
void RPG::setSkills()
{
    if (type == "mage"){
        skills[0] = "fire";
        skills[1] = "thunder";
    }
    
    else if (type == "thief"){
        skills[0] = "pilfer";
        skills[1] = "jab";
    }

    else if(type == "archer") {
        skills[0] = "parry";
        skills[1] = "crossbow_attack";
    }

    else {
        skills[0] = "slash";
        skills[1] = "parry";
    }
}

void RPG::printAction(string skills, RPG opponent) {
    printf("%s used %s on %s\n", name.c_str(), skills.c_str(), opponent.getName().c_str());
}

void RPG::updateHealth(int new_health) {
    health = new_health;
}

bool RPG::isAlive() {
    if (health > 0) {
        return true;
    }

    else {
        return false;
    }
}

void RPG::attack(RPG * opponent){
    int oppHealth = (*opponent).getHealth();
    int oppDefense = (*opponent).getDefense();

    int newHealth = oppHealth - (strength - oppDefense);
    
    (*opponent).updateHealth(newHealth);
}

void RPG::useSkill(RPG * opponent){
    for (int i = 0; i < SKILL_SIZE; i++) {
        printf("Skill %i: %s\n", i, skills[i].c_str());
    }

    int chosenSkillIndex;

    printf("Choose a skill to use: Enter 0 or 1\n");
    cin >> chosenSkillIndex;

    string chosen_skill = skills[chosenSkillIndex];

    printAction(chosen_skill, (*opponent));
    attack(opponent);
}

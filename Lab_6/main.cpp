#include <iostream>
#include "RPG.h"

using namespace std;

void displayStats(RPG player1, RPG player2){
    printf("%s health: %d\n", player1.getName(), player1.getHealth());
    printf("%s health: %d\n", player2.getName(), player2.getHealth());
}

void displayEnd(RPG player1, RPG player2){
    if (player1.isAlive() == false || player2.isAlive() == false) {
        if (player1.getHealth() > player2.getHealth()){
            printf("%s defeated %s! Good game!\n", player1.getName(), player2.getName());
        }

        else {
            printf("%s defeated %s! Good game!\n", player2.getName(), player1.getName());
        }
    }
    
}

void gameLoop(RPG * player1, RPG * player2){
    while (player1->getHealth() != 0 && player2->getHealth() != 0){
        displayStats((*player1), (*player2));

        printf("%s: your turn\n", player1->getName());
        printf("------------------------------\n");

        printf("%s: your turn\n", player2->getName());
        printf("------------------------------\n");

        (*player2).useSkill(player1);
        printf("------------------------------\n");
    }
}



int main() 
{    
    RPG p1 = RPG("Wiz", 70, 45, 15, "mage");
    RPG p2 = RPG();

    gameLoop(&p1, &p2);
    displayEnd(p1, p2);
    return 0;
}

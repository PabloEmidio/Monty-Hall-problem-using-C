#include <stdlib.h>
#include "utils.h"

int getRandomInteger(int maxOption){
    return (rand() % maxOption) + 1;
}

int switchDoor(int playerChoice, int doorWasOpenned){
    if ((playerChoice == 2 && doorWasOpenned == 3) || (playerChoice == 3 && doorWasOpenned == 2)){
        return 1;
    } 
    else if ((playerChoice == 1 && doorWasOpenned == 3) || (playerChoice == 3 && doorWasOpenned == 1)){
        return 2;
    }
    else if ((playerChoice == 1 && doorWasOpenned == 2) || (playerChoice == 2 && doorWasOpenned == 1)){
        return 3;
    }
    else {
        return 0;
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIMULATION_TIMES 500

int main(){
    int carPosition = 0, doorWillBeOpenned = 0, playerChoice = 0, playerWon = 0;
    float winningsPercentage = 0.0;

    srand(time(0));

    for (int i = 1; i < SIMULATION_TIMES; i++){
        carPosition = (rand() % 3) + 1;
        playerChoice = (rand() % 3) + 1;

        do {
            doorWillBeOpenned = (rand() % 3) + 1;
        } 
        while (doorWillBeOpenned == carPosition || doorWillBeOpenned == playerChoice);
        
        if ((playerChoice == 2 && doorWillBeOpenned == 3) || (playerChoice == 3 && doorWillBeOpenned == 2)){
            playerChoice = 1;
        } 
        else if ((playerChoice == 1 && doorWillBeOpenned == 3) || (playerChoice == 3 && doorWillBeOpenned == 1)){
            playerChoice = 2;
        }
        else if ((playerChoice == 1 && doorWillBeOpenned == 2) || (playerChoice == 2 && doorWillBeOpenned == 1)){
            playerChoice = 3;
        }

        if (playerChoice == carPosition){
            playerWon++;
        }
    }

    winningsPercentage = (float)playerWon / (float)SIMULATION_TIMES * 100.0;

    printf("%d matches done, switching the door it\'d win %d times, %.2f of the matches\n", SIMULATION_TIMES, playerWon, winningsPercentage);

    return 0;
}
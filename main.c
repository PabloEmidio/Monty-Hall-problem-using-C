/*
"Suppose you're on a game show, and you're given the choice of three doors: Behind one door is a car; behind the others, goats.
You pick a door, say No. 1, and the host, who knows what's behind the doors, opens another door, say No. 3, which has a goat. He then says to you,
"Do you want to pick door No. 2?" Is it to your advantage to switch your choice?"
source: https://en.wikipedia.org/wiki/Monty_Hall_problem
Based on rep: https://github.com/PabloEmidio/Monty-Hall-problem
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"

int main(){

    if (TOTAL_DOORS_AVAILABLE != PROBLEM_TOTAL_DOORS){
        printf("The problem must have %d doors available, %d was given.\n", PROBLEM_TOTAL_DOORS, TOTAL_DOORS_AVAILABLE);
        return 1; // Indicate a mistake on the total numbers of doors available.
    }

    srand(time(0));

    unsigned short int carPosition = 0, doorWillBeOpenned = 0, playerChoice = 0, playerFinalChoice=0, playerWon = 0;
    float winningsPercentage = 0.0;

    for (int i = 1; i < SIMULATION_TIMES; i++){
        carPosition = getRandomInteger(TOTAL_DOORS_AVAILABLE);
        playerChoice = getRandomInteger(TOTAL_DOORS_AVAILABLE);

        do {
            doorWillBeOpenned = getRandomInteger(TOTAL_DOORS_AVAILABLE);
        } while (doorWillBeOpenned == carPosition || doorWillBeOpenned == playerChoice);
        

        playerFinalChoice = switchDoor(playerChoice, doorWillBeOpenned);

        if (!playerFinalChoice){
            return 2; // Indicate a bad combination between playerChoice and doorWillBeOpenned.
        }


        if (playerFinalChoice == carPosition){
            playerWon++;
        }
    }

    winningsPercentage = (float)playerWon / (float)SIMULATION_TIMES * 100.0;

    printf("%d matches done, switching the door it\'d win %d times, %.1f of the matches\n", SIMULATION_TIMES, playerWon, winningsPercentage);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>


int inputChecker (char k);

int main()
{
    int validInput;
    int validArray[30];
    int equationSize;

    char userInput[30];

    do {
        // resets the array for when the user inputs again
        memset(validArray, 0, sizeof(validArray));
        memset(userInput, 0, sizeof(userInput));
        equationSize = 0;

        printf("\nEnter the equation you'd like solved: ");
        if (!fgets(userInput, 30, stdin)) {
            return 1;
        }


        // loops through the userInput and mark the positions where the char is not a number/op
        int i;
        for (i = 0; i < 30; i++) {
            int check = inputChecker(userInput[i]);

            if (check == 1) {
                validArray[i] = 1;
            } else if (check == 0) {
                validArray[i] = 0;
            } else {
                printf("wut");
            }
        }

        // checks for invalid characters in the equation and find the equation size
        for (i = 0; i < 29; i++) {
            if (validArray[i] == 0 && validArray[i+1] == 1) {
                printf("\nThere were invalid characters in that equation");
                validInput = 0;
            } else if (validArray[i] == 1) {
                equationSize++;
            }
        }

    } while (!validInput);

    return 0;
}

int inputChecker (char k) {

    char validChars[16] = {'1','2','3','4','5','6','7','8','9','0','*','/','+','-',')','('};

    int j;
    int x = 0;
    for (j = 0; j < 16; j++) {
            if (k == validChars[j]) {
                x = 1;
            }
        }
        if (x == 1) {
            return 1;
        } else {
            return 0;
        }
}

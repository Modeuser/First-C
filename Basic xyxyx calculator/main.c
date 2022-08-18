#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main()
{
    double num1;
    double num2;
    double num3;
    char cnum1[20];
    char cnum2[20];
    char cnum3[20];

    int opID1;
    int opID2;

    char op1;
    char op2;
    char userInput[20];

    double result;



    printf("Enter an operation xyxyx, where x is a number and y is a operator: ");
     if (!fgets(userInput, 20, stdin)) {
        return 1;
     }

    int i;
    // this "for" statement will find the first operator and id its location
    for (i = 0; i < 20; i++) {
        if (userInput[i] == '*' || userInput[i] == '+' || userInput[i] == '-' || userInput[i] == '/') {
            op1 = userInput[i];
            opID1 = i;
            break;
        }
    }

    // this "for" statement will find the second operator and id its location
    for (i = 20; i > 0; i--) {
        if (userInput[i] == '*' || userInput[i] == '+' || userInput[i] == '-' || userInput[i] == '/') {
            op2 = userInput[i];
            opID2 = i;
            break;
        }
    }

    // this "for statement will find the first number using opID1's location

    for (i = 0; i < opID1; i++) {
        cnum1 [i] = userInput[i];
        num1 = atof(cnum1);
    }
    int j = 0;
    // this "for statement will find the last number using opID2's location
    for (i = opID2+1; i < 20; i++) {
        cnum3 [j] = userInput[i];
        num3 = atof(cnum3);
        j++;
    }
    j = 0;
    // this "for statement will find the middle number using both ID's location
    for (i = opID1+1; i < opID2; i++) {
        cnum2 [j] = userInput[i];
        num2 = atof(cnum2);
        j++;
    }

    //checking for zeros
    if (num2 == 0 || num3 == 0) {
        printf("cannot divide by zero");
        exit(0);
    }

    //debugging
    //printf("%c, %c, %s, %d, %d, %d", op1, op2, userInput, num1, num2, num3);

    // these "if" "switch" statements determines which equation to use based on BEDMAS
    if (op1 == op2) {
        switch (op1) {
        case ('+'):
            result = num1 + num2 + num3;
            break;
        case ('-'):
            result = num1 - num2 - num3;
            break;
        case ('*'):
            result = num1 * num2 * num3;
            break;
        case ('/'):
            result = num1 / num2 / num3;
            break;
        }
    } else if (op1 == '+') {
        switch (op2) {
        case ('-'):
            result = num1 + num2 - num3;
            break;
        case ('/'):
            result = num1 + num2 / num3;
            break;
        case ('*'):
            result = num1 + num2 * num3;
            break;
        }
    } else if (op1 == '-') {
        switch (op2) {
        case ('+'):
            result = num1 - num2 + num3;
            break;
        case ('/'):
            result = num1 - num2 / num3;
            break;
        case ('*'):
            result = num1 - num2 * num3;
            break;
        }
    } else if (op1 == '*') {
        switch (op2) {
        case ('-'):
            result = num1 * num2 - num3;
            break;
        case ('+'):
            result = num1 * num2 + num3;
            break;
        case ('/'):
            result = num1 * num2 / num3;
            break;
        }
    } else if (op1 == '/') {
        switch (op2) {
        case ('-'):
            result = num1 / num2 - num3;
            break;
        case ('+'):
            result = num1 / num2 + num3;
            break;
        case ('*'):
            result = num1 / num2 * num3;
            break;
        }
    }
    //print the result
    printf("%f", result);

    return 0;
}

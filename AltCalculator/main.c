#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <string.h>

// a struct to store a t/f value, along with a union for either number or char
struct checker {
    bool validInput;
    int numop;

};

// a struct that checks if k is a number, and returns the number along with a t/f value
struct checker numChecker (char k) {
    char validChars[10] = {'1','2','3','4','5','6','7','8','9','0'};

    int j, x;
    int u = 0;
    for (j = 0; j < 10; j++) {
        if (k == validChars[j]) {
            x = k - '0';
            u = 1;
        }
    }

    if (u == 1) {
        struct checker r = {true, x};
        return r;
    } else {
        struct checker r = {false, x};
        return r;
    }
}

struct checker opChecker (char k) {
    if (k == '(') {
        struct checker r = {true, 1};
        return r;
    } else if (k == ')') {
        struct checker r = {true, 2};
        return r;
    } else if (k == '*') {
        struct checker r = {true, 3};
        return r;
    } else if (k == '/') {
        struct checker r = {true, 4};
        return r;
    } else if (k == '+') {
        struct checker r = {true, 5};
        return r;
    } else if (k == '-') {
        struct checker r = {true, 6};
        return r;
    } else {
        struct checker r = {false, 0};
        return r;
    }
}


int main()
{
    //debuggering variables
    bool looper = true;
    //

    int intSize = 2;
    int charSize = 1;
    int *buffer = malloc(sizeof(int)*intSize); // size of int is 4 bytes, therefore we've allocated 8 bytes

    int equationSize = 0;

    printf("Please enter an equation, one character at a time");
    while (looper) {
        printf("\nEnter the next number/operator, or end with an alphabet character: ");
        int c;
        c = fgetc(stdin);

        struct checker t = numChecker(c);
        struct checker op = opChecker(c);

        if (t.validInput) {
            //debugging
            printf("num input");
            printf("%d", t.numop);
            //

            buffer[equationSize] = t.numop;
            equationSize++;


            looper = true;
        } else if (op.validInput) {
            //debugging
            printf("op input");
            printf("%d", op.numop);
            //

            buffer[equationSize] = op.numop;
            equationSize++;

            looper = true;
        } else if (!t.validInput && !op.validInput){
            printf("\nEnding equation");
            looper = false;
        }

        // allocate more bytes if the equation size becomes larger than our initial buffer size
        // update the startSize to a new size
        if (equationSize == intSize) {
            intSize = intSize*2;
            buffer = realloc(buffer, sizeof(int)*intSize);
        }

    }
    // once the program exits the loop, we should have a full equation

    //print the whole equation
    printf("\n%d", *buffer);

    return 0;
}

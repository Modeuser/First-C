#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
/*will be explained later*/
// it turns out C# comments works here too

///* Printing with variables*/
//int main()
//{
//    char characterName[] = "John";
//    int characterAge = 35;
//
//    printf("There was a man named %s\n", characterName);
//    printf("he was %d\n", characterAge);
//
//    characterAge = 70;
//    printf("He really liked %s\n", characterName);
//    printf("but did not like being %d.\n", characterAge);
//
//    return 0;
//}

///* Data types*/
//int main()
//{
//    int age = 40;
//    //double has double (64) the bits of floats (32)
//    double gpa = 3.7;
//    //char can only store one character
//    char grade = 'F';
//    //to string a bunch of charaters together, use a char array
//    char phrase[] = "F for failed";
//
//    return 0;
//}

///* Printf*/
//int main()
//{
//    printf("Hello\""); //backslash is a modifier
//    //%s for string, %d for digits, %c for single characters, %f for floats
//    printf("My favorite %s is %d", "number", 500); //% is a modifier that acts as a place holder
//
//
//    return 0;
//}

///* Working with numbers*/
//int main()
//{
//
//    printf("%f", pow(2, 3));
//    printf("%f", sqrt(2, 3));
//    printf("%f", ceil(2, 3)); // always rounds up
//    printf("%f", floor(2, 3)); // always rounds down
//
//    return 0;
//}

///* Constants*/
//int main()
//{
//    const int num = 5;
//    printf("%d", num);
//    num = 8;
//    printf("%d", num);
//
//    return 0;
//}

///* Getting user inputs*/
//int main()
//{
//    char name[20];
//    printf("Please enter your name: ");
//    //scanf("%s", name); //allows the user to input something, and stores it into the "age" variable
//    //scanf only grabs characters upto the first "space"
//    fgets(name, 20, stdin); // fgets only works for strings, 20 characters are allowed, "stdin" will ask "fgets" to obtain the input from the terminal
//    printf("Your name is %s", name);
//
//    return 0;
//}

///* Calculater*/
//int main()
//{
//    double num1;
//    double num2;
//    double numf;
//    int op;
//
//    printf("please enter the first number: ");
//    scanf("%lf", &num1);
//    printf("please enter the second number: ");
//    scanf("%lf", &num2);
//    printf("please enter an operator: ");
//    scanf("%d", &op);
//
//    switch(op) {
//    case 1:
//        numf = num1 + num2;
//        break;
//    case 2:
//        numf = num1 - num2;
//        break;
//    case 3:
//        numf = num1 * num2;
//        break;
//    default:
//        printf("operator is not valid");
//    }
//
//    printf("the result is: %lf", numf);
//    return 0;
//}

///* Madlib*/
//int main()
//{
//    char color[20];
//    char pluralNoun[20];
//    char celebrityF[20];
//    char celebrityL[20];
//
//    printf("Enter a color: ");
//    scanf("%s", color);
//    printf("Enter a plural noun: ");
//    scanf("%s", pluralNoun);
//    printf("Enter a celebrity: ");
//    scanf("%s%s", celebrityF, celebrityL);
//
//    printf("Roses are %s\n", color);
//    printf("%s are blue\n", pluralNoun);
//    printf("I love %s %s\n", celebrityF, celebrityL);
//
//    return 0;
//}

///* Arrays*/
//int main()
//{
//    int luckyNumbers[] = {3, 90, 88, 50, 44};
//    luckyNumbers[1] = 200;
//    printf("%d", luckyNumbers[1]);
//
//    return 0;
//}

///* Functions*/
//int main()
//{
//    sayHi();
//    return 0;
//}
//
//void sayHi (){
//    printf("hello");
//}

///* Return functions*/
// if you want to place this function below "main"
// you can prototype by placing "double cube(double num)" on the top
//double cube(double num){
//    double result = num * num * num;
//    return result;
//}
//
//int main()
//{
//
//    printf("Answer: %f", cube(3.0));
//    return 0;
//}

///* Build a better calculator*/

//int main()
//{
//    double num1;
//    double num2;
//    double numf;
//    char op1;
//
//    printf("Please enter num1: ");
//    scanf("%lf", &num1);
//    printf("Please enter first operator");
//    scanf(" %c", &op1);
//    printf("Please enter num2: ");
//    scanf("%lf", &num2);
//
//
//    switch (op) {
//    case ('+'):
//        numf = num1 + num2;
//        break;
//    case ('-'):
//        numf = num1 - num2;
//        break;
//    case ('/'):
//        if (num2 == 0) {
//            printf(" \ncannot divide by 0");
//            break;
//        }
//        numf = num1 / num2;
//        break;
//    case ('*'):
//        numf = num1 * num2;
//        break;
//    default:
//        printf("operator is not valid");
//    }
//
//    printf("The answer is: %lf", numf);
//
//    return 0;
//}

int main()
{
    int num1;
    int num2;
    int num3;
    char cnum1[20];
    char cnum2[20];
    char cnum3[20];

    int opID1;
    int opID2;

    char op1;
    char op2;
    char userInput[20];

    int result;


    printf("Enter an operation xyxyx, where x is a number and y is a operator: ");
    fgets(userInput, 20, stdin);
    printf("%s", userInput);

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
        num1 = atoi(cnum1);
    }
    int j = 0;
    // this "for statement will find the last number using opID2's location
    for (i = opID2+1; i < 20; i++) {
        cnum3 [j] = userInput[i];
        num3 = atoi(cnum3);
        j++;
    }
    j = 0;
    // this "for statement will find the middle number using both ID's location
    for (i = opID1+1; i < opID2; i++) {
        cnum2 [j] = userInput[i];
        num2 = atoi(cnum2);
        j++;
    }

    //checking for zeros
    if (num2 == 0 || num3 == 0) {
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
    printf("%d", result);

    return 0;
}



///* Structs*/
///structs can act just like variables once they are instantiated
//struct Student{
//    char name[50];
//    char major[50];
//    int age;
//    double gpa;
//};
//
//int main()
//{
//    struct Student student1;
//    student1.age = 22;
//    student1.gpa = 3.2;
//    strcpy( student1.name, "Jim");
//    strcpy( student1.major, "Business");
//
//    return 0;
//}

///* While loop guessing game*/

//int main()
//{
//    int secretnum = 15;
//    int usernum;
//    int exitcon = 1;
//    do {
//        printf("guess the random number!");
//        scanf("%d", &usernum);
//        if (usernum > secretnum) {
//            printf("too big! \n");
//        } else if(usernum < secretnum) {
//            printf("too small \n");
//        } else if (usernum == secretnum) {
//            printf("correct! \n");
//            exitcon = 0;
//        }
//    } while (exitcon);
//
//    return 0;
//}

///* 2D arrays and nested loops*/

//int main()
//{
//    // 3 items in the array, each item is an array of 2
//    int nums [3][2] = {
//                {1,2},
//                {3,4},
//                {5,6}
//    };
//    int i,j;
//    for (i = 0; i < 3; i++) {
//        for (j = 0; j < 2; j++){
//            printf("%d", nums[i][j]);
//        }
//    }
//
//    return 0;
//}

///* Memory address*/
//
//int main()
//{
//    int age = 30;
//    double gpa = 3.4;
//    char grade = 'A';
//
//    printf("%p", &age);
//
//
//    return 0;
//}

///* Working with pointers*/
//
//int main()
//{
//    int age = 30;
//    int * pAge = &age;
//    printf("age's memory address: %p\n", &age);
//
//
//    return 0;
//}

///* Writing files*/

//int main()
//{
//    FILE * fpointer = fopen("employees.txt", "w"); //replace "w" with "a" to append
//
//    // file pointer
//    fprintf(fpointer, "Jim, Salesman\nPam, Receptionist\nOscar Accounting");
//
//    fprintf(fpointer, "\nKelly, Customer Service");
//
//    fclose(fpointer);
//    return 0;
//}

///* Writing files*/

//int main()
//{
//    char line[255];
//
//    FILE * fpointer = fopen("employees.txt", "r"); //replace "w" with "a" to append
//    //fgets (where to store, max size allowed to be read-in, which file?)
//    fgets(line, 255, fpointer);
//    printf("%s", line);
//
//    fclose(fpointer);
//    return 0;
//}

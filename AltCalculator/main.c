#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>

int main()
{
    int c;
    c = fgetc(stdin);
    printf("%c", c);



    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int Func(int (*A)[2][2]) {


}

int main()
{
    int c[3][2][2] = {{{2,5},{7,9}}, {{3,4},{6,1}},{{0,8},{11,13}}};

    printf("%d %d %d %d", c, *c, c[0], &c[0][0]);
    printf("\n%d", *(c[0][0]+1));
}

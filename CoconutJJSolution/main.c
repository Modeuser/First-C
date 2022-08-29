#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool isNumeral (char c)
{
        return '0' <= c && c <= '9';
}

bool isEquationChar (char c)
{
        switch (c) {
        case '(':
        case ')':
        case '*':
        case '/':
        case '+':
        case '-': return true;
        default: return false;
        }
}

int main (int argc, char **argv)
{
        char *buf = NULL;
        size_t buf_size = 0;
        size_t buf_count = 0;
        int c;

        while ((c = fgetc (stdin)) != EOF) {

                if (!isEquationChar(c) && !isNumeral(c))
                        break;

                if (buf_count + 1 >= buf_size) {
                        if (buf_size == 0)
                                buf_size = 10;
                        else
                                buf_size *= 2;

                        buf = realloc (buf, buf_size);

                        if (!buf) {
                                perror ("realloc");
                                exit (EXIT_FAILURE);
                        }
                }

                buf[buf_count++] = c;
        }
        buf[buf_count] = '\0';

        // print all values from buffer
        size_t o;
        for (o = 0; o < buf_count; o++) {
            printf("%c", *buf++);
        }
        printf("\n%d", sizeof(size_t));
}

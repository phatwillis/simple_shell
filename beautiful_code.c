#include "shell.h"

/**
 * simple_arithmetic - Simple arithmetic C program
 *
 * Description: Print basic arithmetic code
 * of two declared integers
 *
 * Return: 0 on Success
 */

int simple_arithmetic(void)
{
        int a = 4;
        int b = 2;

        /* Arithmetic processes */
        int sum = a + b;
        int subtraction = a - b;

        printf("sum: %d\n", sum);
        printf("subtraction: %d\n", subtraction);

        return (0);
}

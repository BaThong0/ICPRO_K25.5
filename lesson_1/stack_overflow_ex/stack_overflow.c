#include <stdio.h>

void stack_overflow()
{
    stack_overflow();
}

int main()
{
    printf("Calling stack overflow function\n");
    stack_overflow();
    return 0;
}
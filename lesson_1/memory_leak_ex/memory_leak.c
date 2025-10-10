#include <stdio.h>

void memory_leak_func() 
{
    int size = 10;
    int* ptr = (int*)malloc(size*sizeof(int));
}

int main() 
{
    printf("Calling memory leak function\n");
    memory_leak_func();
    return 0;
}
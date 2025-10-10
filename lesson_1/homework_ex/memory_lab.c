#include <stdio.h>
#include <string.h>

void out_of_memory_func()
{
    size_t size = 1024UL*1024UL*1024UL;
    void*ptr;

    while(1) {
        ptr = malloc(size);
        if(ptr == NULL)
        {
            printf("Out of memory\n");
            break;
        }
        else 
        {
            printf("Allocated %zu bytes\n", size);
        }
    }
}

void memory_leak_func() 
{
    int size = 10;
    int* ptr = (int*)malloc(size*sizeof(int));
}

void stack_overflow_func()
{
    stack_overflow_func();
}

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        printf("Usage: %s [option\n]", argv[0]);
        return 1;
    } else 
    {
        if(strcmp(argv[1], "memory_lab_stack_overflow") == 0)
        {
            printf("Runing stack overflow program\n");
            stack_overflow_func();
        }
        else if (strcmp(argv[1], "memory_lab_memory_leak") == 0)
        {
            printf("Running memory_lab_memory_leak\n");
            memory_leak_func();
        }
        else if(strcmp(argv[1], "memory_lab_out_of_memory") == 0)
        {
            printf("Running out of memory program\n");
            out_of_memory_func();
        }
        else 
        {
            printf("Unknown option %s\n", argv[1]);
            return 1;
        }
    }
    return 0;
}
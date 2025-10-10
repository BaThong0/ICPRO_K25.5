#include <stdio.h>
#include <stdlib.h>

int main() 
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
    return 0;
}
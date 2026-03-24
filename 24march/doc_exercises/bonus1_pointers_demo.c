#include <stdio.h>

int main(void)
{
    int value = 42;
    int *ptr = &value;

    printf("Variable value: %d\n", value);
    printf("Variable address: %p\n", (void*)&value);
    printf("Pointer value (address it stores): %p\n", (void*)ptr);
    printf("Value through pointer: %d\n", *ptr);

    *ptr = 100;
    printf("After change through pointer, value = %d\n", value);

    return 0;
}

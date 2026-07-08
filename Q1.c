#include <stdio.h>

int main() {
    int a = 10, b = 20, sum;
    int *aptr = &a, *bptr = &b, *sumptr = &sum;

    printf("Numbers: %d and %d\n", a, b);
    printf("Address:\n%d: %p\n%d: %p\n", a, (void*)aptr, b, (void*)bptr);
    *sumptr = *aptr + *bptr;
    printf("Sum: %d\nAddress: %p", sum , (void*)sumptr);

    return 0;
}
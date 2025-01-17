#include <stdio.h>

// Function that takes three integers by reference and returns their sum
int add(int *a, int *b, int *c) {
    return *a + *b + *c;
}

int main() {
    int x, y, z, sum;

    // Input three integers
    printf("Enter three integers: ");
    scanf("%d %d %d", &x, &y, &z);

    // Call the add function with references to the integers
    sum = add(&x, &y, &z);

    // Output the result
    printf("The sum of %d, %d, and %d is: %d\n", x, y, z, sum);

    return 0;
}

#include <stdio.h>

int main(void) {
    int numbers[5] = {7, 2, 5, 3, 8};
    int product = 1;

    for (int i = 0; i < 5; i++) {
        product = product * numbers[i];
    }
    printf("%d\n", product);
    return 0;
}
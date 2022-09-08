#include <stdio.h>
int cube(int n) {
    n = n * n * n;
    return n;
}

int main(void) {
   int dozen = 12;
   printf("After call, result is %i\n", cube(dozen));
   return 0;
}

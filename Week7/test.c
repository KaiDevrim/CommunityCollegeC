typedef int whole_number;
typedef int countable;

void f(whole_number n) {
   printf("f: %d\n", n);
}


int main(void) {
       countable c = 10;
   
   f(c);
   return 0;
}

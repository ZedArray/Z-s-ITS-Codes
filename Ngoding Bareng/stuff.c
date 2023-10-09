#include <stdio.h>
#include <math.h>
#include <string.h>
int main() {
    int x, y;
    x = 5;
    y = 2;
    char lmao[10] = "bruh";
    printf("%s\n", lmao);
    strcpy(lmao, "hello");
    printf("%s\n", lmao);
    scanf("%s", lmao);
    printf("%s\n", lmao);
    
    printf("x + y = %d\nx - y = %d\nx * y = %d\nx / y = %.1f\nx %% y = %d\n", x+y, x-y, x*y, (float)x/y, x%y);

    /* 
    x + y = 7
    x - y = 3
    x * y = 10
    x / y = 2.5
    x % y = 1
    */
    return 0;
}
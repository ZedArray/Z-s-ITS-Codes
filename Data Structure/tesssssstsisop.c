#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
int main() {

    srand(time(NULL));
    for(int i = 0; i < 10; i++){
        printf("%d\n", rand() % 4000);
    }

    return 0;
}
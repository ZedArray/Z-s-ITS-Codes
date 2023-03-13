#include <stdio.h>
int main(){
    int n, sum = 0;
    scanf("%d",&n);
    int input[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &input[i]);
    }
    for (int i = 0; i < n; i++){
        for(int j = i; j >= 0; j--){
            if (input[j] <= input[i]){
                sum++;
            }
            else{
                break;
            }
        }
    }
    printf("%d\n", sum);
}
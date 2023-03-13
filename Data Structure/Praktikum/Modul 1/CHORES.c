#include <stdio.h>
#include <string.h>
#include <math.h>
int main(){
    int e, n;
    scanf("%d %d",&e,&n);
    char tasks[n][100];
    int used[n];
    int index[n];
    for(int i=0; i<n; i++){
        index[i] = i;
    }
    for(int i=0; i<n; i++){
        scanf(" %d %s", &used[i], tasks[i]);
    }
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++)
        if(used[i] >= used[j]){
            int temp = used[i];
            used[i] = used[j];
            used[j] = temp;
            temp = index[i];
            index[i] = index[j];
            index[j] = temp;
        }
    }
    // for(int i = 0; i < n; i++){
    //     printf("%d\n", used[i]);
    //     printf("%d\n", index[i]);
    // }
    int indicator = 0;
    for(int i = 0; i < n; i++){
        e -= used[i];
        if(e >= 0){
            printf("%s\n", tasks[index[i]]);
            indicator = 1;
        }
        else if(e < 0){
            if(indicator == 0){
                printf("Pak Aya will do the rest");
            }
            break;
        }
    }
    return 0;
}
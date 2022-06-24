#include <stdio.h>

int t, n;

int main(void){
    int i;

    scanf("%d",&t);
    for(i=0; i<t; i++){
        scanf("%d", &n);
        if(n==4){
            printf("1 1 1 1\n");
        }
        else if(n%2==1){
            printf("2 %d 1 1 \n", n-4);
        }
        else{
            printf("1 %d 1 1 \n", n-3);
        }
    }


    return 0;
}

#include <stdio.h>

int  main(void){
    int i,t;

    scanf("%d",&t);
    while(t--){
        int score;
        scanf("%d",&score);
        if(score>=1900) printf("Division 1\n");
        else if(score>=1600) printf("Division 2\n");
        else if(score>=1400) printf("Division 3\n");
        else printf("Division 4\n");
    }
    return 0;
}
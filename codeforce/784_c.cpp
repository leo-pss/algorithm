#include <stdio.h>

int main(void){
    int i, t;

    scanf("%d",&t);
    while(t--){
        int n, x;
        scanf("%d",&n);
        int odd,even;
        scanf("%d",&x);
        odd = x%2;
        scanf("%d",&x);
        even = x%2;
        int check = 1;
        for(i=3; i<=n; i++){
            scanf("%d",&x);
            if(i%2==1 && odd != x%2){
                check = 0;
            }
            if(i%2==0 && even != x%2){
                check = 0;
            }
        }
        if(check) printf("YES\n");
        else printf("NO\n");
        
    }
    return 0;
}
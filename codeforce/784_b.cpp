#include <stdio.h>
#include <algorithm>

using namespace std;

int a[200000];

int main(void){
    int i,t;

    scanf("%d",&t);
    while(t--){
        int n,x;
        scanf("%d",&n);
        for(i=1; i<=n; i++){
            a[i]=0;
        }
        for(i=1; i<=n; i++){
            scanf("%d",&x);
            a[x]++;
        }
        int chk = 0;
        for(i=1; i<=n; i++){
            if(a[i]>=3){
                chk=i;
                break;
            }
        }
        if(chk==0) printf("-1\n");
        else printf("%d\n",chk);
    }
    return 0;
}
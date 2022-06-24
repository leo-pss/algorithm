#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int a[100011];

int main(void){
    int i;

    scanf("%d",&n);
    for(i=1; i<=n; i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);

    int ans = 0;
    for(i=(n/2)+1; i<=n; i++){
        ans += a[i];
    }
    ans*=2;
    if(n%2==1){
        ans-=a[n/2+1];
    }
    printf("%d",ans);

    return 0;
}
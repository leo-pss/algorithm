#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int m,n;
int c[100001];
ll sum;
ll answer;

int main(void){
    int i;
    ll x,y;

    scanf("%d %d",&m,&n);
    sum-=(ll)m;
    for(i=1; i<=n; i++){
        scanf("%d",&c[i]);
        sum+=(ll)c[i];
    }
    sort(c+1,c+n+1);

    for(i=1; i<=n; i++){
        x=min((ll)c[i],sum/(n-i+1));
        answer+=x*x;
        sum-=x;
    }
    printf("%lld",answer);

    return 0;
}
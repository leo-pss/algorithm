#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

const int MAX = 500011;
typedef long long ll;
int n,m;
pair<ll,ll> a[MAX];
map<ll,ll> M;

int main(void){
    int i;
    long long x,y;

    scanf("%d %d",&n,&m);
    for(i=1; i<=n; i++){
        scanf("%lld %lld",&x,&y);
        a[i].first=y; a[i].second=-x;
    }
    for(i=1; i<=m; i++){
        scanf("%lld %lld",&x,&y);
        if(M.find(x)==M.end()) M.insert({x,y});
        else M[x]+=y;
    }
    sort(a+1,a+n+1);
    int answer=0;
    for(i=1; i<=n; i++){
        x=-a[i].second; y=a[i].first;

        auto lb = M.lower_bound(x);
        if(lb->first<=y){
            lb->second--;
            answer++;
            if(lb->second==0) M.erase(lb->first);
        }
    }
    printf("%d",answer);
    return 0;
}
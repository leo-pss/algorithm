#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> PII;
const int MAX = 1000011;

struct line{  // y = a*x + b
    long long a,b;
};
 
struct convexhull_trick{
    int s=0,e=0;
    int idx[MAX];
    line deq[MAX];
    double cross(int a, int b) {
        return 1.0 * (deq[a].b - deq[b].b) / (deq[b].a - deq[a].a);
    }
    void insert(line v,int line_idx){
        deq[e] = v;
        idx[e] = line_idx;
        while(s+1<e && cross(e - 2, e - 1) > cross(e - 1, e)){
            deq[e-1] = deq[e];
            idx[e-1] = idx[e];
            e--;
        }
        e++;
    }
    PII query(ll x){  // query가 증가수열일 경우
        while(s+1<e && deq[s+1].b - deq[s].b >= x * (deq[s].a - deq[s+1].a))
            s++;
        return PII(deq[s].a*x+deq[s].b,idx[s]);
    }
    PII query2(ll x){ // 일반 query
        int l = 0, r = e - 1;
        while (l != r) {
            int m = (l + r) / 2;
            if (cross(m, m + 1) <= x) l = m + 1;
            else r = m;
        }
        return PII(deq[l].a*x+deq[l].b,idx[l]);
    }
    void clear(){s = e = 0;}
}cht;

int n;
ll x[MAX];
ll sum[MAX];
ll d[MAX];
ll a,b,c;

int main(void){
    int i;

    scanf("%d",&n);
    scanf("%lld %lld %lld",&a,&b,&c);
    for(i=1; i<=n; i++){
        scanf("%lld",&x[i]);
        sum[i]=sum[i-1]+x[i];
    }
    cht.clear();
    line tmp;
    tmp.a=0; tmp.b=0;
    cht.insert(tmp,0);
    for(i=1; i<=n; i++){
        d[i] = a*sum[i]*sum[i] + b*sum[i] + c + cht.query2(sum[i]).first;
        tmp.a = -2*a*sum[i];
        tmp.b = a*sum[i]*sum[i] - b*sum[i] + d[i];
        cht.insert(tmp,i);
    }
    printf("%lld",d[n]);

    return 0;
}
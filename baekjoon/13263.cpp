#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 100001;

struct LinearF{
    long long a,b;
    double s;
    LinearF(): LinearF(1,0) {}
    LinearF(long long a1, long long b1): a(a1), b(b1), s(0) {}
};

double cross(LinearF &f, LinearF &g){
    return 1.0 * (double)(g.b-f.b)/(f.a-g.a);
}

int n, A[MAX], B[MAX];
long long d[MAX];
LinearF f[MAX];

int main(void){
    int i;

    scanf("%d",&n);
    for(i=1; i<=n; i++) scanf("%d",&A[i]);
    for(i=1; i<=n; i++) scanf("%d",&B[i]);

    int top=0;
    for(i=2; i<=n; i++){
        LinearF g(B[i-1],d[i-1]);
        while(top>0){
            g.s=cross(f[top-1],g);
            if(f[top-1].s < g.s) break;
            top--;   
        }
        f[top++]=g;
        long long x = A[i];
        int fpos = top-1;
        if(x<f[top-1].s){
            int l=0, r=top-1;
            while(l+1<r){
                int w=(l+r)/2;
                if(x<f[w].s) r=w;
                else l=w;
            }
            fpos=l;
        }
        d[i]=f[fpos].a*x+f[fpos].b;
    }
    printf("%lld",d[n]);
    return 0;
}
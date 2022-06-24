#include<bits/stdc++.h>

using namespace std;

typedef complex<double> cdbl;

using ll = long long;

using cdbl = complex<double>;
 
const double PI = acos(-1);

inline unsigned bitreverse(const unsigned n, const unsigned k) {
    unsigned r, i;
    for (r = 0, i = 0; i < k; ++i)
        r |= ((n >> i) & 1) << (k - i - 1);
    return r;
}

void fft(vector<cdbl> &a, bool is_reverse=false) {
    const unsigned n = a.size(), k = __builtin_ctz(n);
    unsigned s, i, j;
    for (i = 0; i < n; i++) {
        j = bitreverse(i, k);
        if (i < j)
            swap(a[i], a[j]);
    }
    for (s = 2; s <= n; s *= 2) {
        double t = 2*PI/s * (is_reverse? -1 : 1);
        cdbl ws(cos(t), sin(t));
        for (i = 0; i < n; i += s) {
            cdbl w(1);
            for (j = 0; j < s/2; j++) {
                cdbl tmp = a[i + j + s/2] * w;
                a[i + j + s/2] = a[i + j] - tmp;
                a[i + j] += tmp;
                w *= ws;
            }
        }
    }
    if (is_reverse)
        for (i = 0; i < n; i++)
            a[i] /= n;
}

const int N = 1000011;
int ans[N];
int b[N];
int c[N];
int n;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int i;
    ll x;
    string p,q;
    unsigned np;

    scanf("%d",&n);
    for (np = 1; np < 2*n; np *= 2);
    vector<cdbl> a(np);
    vector<cdbl> aa(np,0);
    for(i=1; i<=n-1; i++){
        x=(1LL*i*i)%n;
        a[x]+=1;
        b[x]+=1;
        c[(x*2)%n]+=1;
    }
    for (i = 0; i < n; i++)
        aa[i]=aa[np-n+i]=a[(n-i)%n];

    
    fft(a);
    fft(aa);
    for (i = 0; i < np; i++)
        a[i] *= aa[i];
    fft(a, true);

    ll ans=0;
    for(i=0; i<=n-1; i++){ 
        int y = (int)(a[i].real() + (a[i].real() > 0? 0.5L : -0.5L));
        y+=c[i];
        ans+=(1LL*y*b[i]);
    }
    ans/=2;
    printf("%lld",ans);
    

    return 0;
}
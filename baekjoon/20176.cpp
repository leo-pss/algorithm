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
        vector<cdbl> w(s/2);
        for (i = 0; i < s/2; i++) {
            long double t = 2*PI*i/s * (is_reverse? -1 : 1);
            w[i] = cdbl(cos(t), sin(t));
        }
        for (i = 0; i < n; i += s) {
            for (j = 0; j < s/2; j++) {
                cdbl tmp = a[i + j + s/2] * w[j];
                a[i + j + s/2] = a[i + j] - tmp;
                a[i + j] += tmp;
            }
        }
    }
    if (is_reverse)
        for (i = 0; i < n; i++)
            a[i] /= n;
}

void convolution(vector<cdbl> &a, vector<cdbl> &b) {
    const unsigned n = a.size();
    unsigned np = n, i;
 
    if (n & (n-1)) {
        for (np = 1; np < 2*n; np *= 2);
        a.resize(np);
        b.resize(np);
        for (i = 0; i < n; i++)
            b[np-n+i] = b[i];
    }
 
    fft(a);
    fft(b);
    for (i = 0; i < np; i++)
        a[i] *= b[i];
    fft(a, true);
 
    if (n & (n-1)) {
        a.resize(n);
        b.resize(n);
    }
}

const int N = 120001;
int na,nb,nc;
int aa[50011];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int i,j,x;

    vector<cdbl> a(N);
    vector<cdbl> b(N);
    scanf("%d",&na);
    for(i=1; i<=na; i++)
    {
        scanf("%d",&x);
        a[x+30000]=1;
    }
    scanf("%d",&nb);
    for(i=1; i<=nb; i++)
    {
        scanf("%d",&x);
        aa[i]=x+30000;
    }
    scanf("%d",&nc);
    for(i=1; i<=nc; i++)
    {
        scanf("%d",&x);
        b[x+30000]=1;
    }
    convolution(a,b);
    long long cnt=0;
    for(i=1; i<=nb; i++){
        x=aa[i]*2;
        long long y = (long long)(a[x].real() + (a[x].real() > 0? 0.5L : -0.5L));
        cnt+=y;
    }
    printf("%lld",cnt);

    return 0;
}
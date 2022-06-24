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

const int N = 1000001;
int pr[N];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int i,j;

    vector<cdbl> a(N);
    vector<cdbl> b(N);
    pr[0]=1;
    pr[1]=1;
    for(i=2; i<=1000; i++){
        if(pr[i]==1) continue;
        for(j=i*2; j<=N-1; j+=i){
            pr[j]=1;
        }
    }
    for(i=0; i<=N-1; i++){
        if(i!=2 && pr[i]==0) a[i]=1;
        else a[i]=0;
    }
    for(i=0; i<=1000000; i++){
        b[i]=0;
    }
    for(i=1; i<=500000; i++){
        if(pr[i]==0) b[i*2]=1;
    }
    convolution(a,b);
    
    int m;
    scanf("%d",&m);
    for(i=0; i<m; i++){
        int x;
        scanf("%d",&x);
        printf("%lld\n",(long long)(a[x].real() + (a[x].real() > 0? 0.5L : -0.5L)));
    }

    return 0;
}
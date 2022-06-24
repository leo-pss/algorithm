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

const int N = 600011;
int ans[N];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int i,j,x;
    string p,q;

    vector<cdbl> a(N);
    vector<cdbl> b(N);
    cin >> p >> q;
    x=p.size();
    for(i=0; i<x; i++){
        a[x-1-i]=(int)(p[i]-'0');
    }
    x=q.size();
    for(i=0; i<x; i++){
        b[x-1-i]=(int)(q[i]-'0');
    }
    convolution(a,b);
    
    for(i=0; i<N; i++){
        int y = (int)(a[i].real() + (a[i].real() > 0? 0.5L : -0.5L));
        ans[i]+=y;
        ans[i+1]+=(int)(ans[i]/10);
        ans[i]=ans[i]%10;
    }
    int chk=0;
    for(i=N-1; i>=0; i--){
        if(ans[i]!=0) chk=1;
        if(chk==1) printf("%d",ans[i]);
    }
    if(chk==0) printf("0");

    return 0;
}
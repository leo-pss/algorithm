#include<bits/stdc++.h>

using namespace std;

typedef complex<double> cdbl;

using ll = long long;

using cdbl = complex<double>;
 
const double PI = acos(-1);


void fft(vector<cdbl> &a, bool inv=false) {
	int n = a.size();
	// bit reversal
	for(int i=1,j=0;i<n;++i) {
		int bit = n>>1;
		while(!((j^=bit) & bit)) bit >>=1;
		if(i<j) swap(a[i],a[j]);
	}
	for(int i=1;i<n;i<<=1) {
		double x = inv? M_PI / i : -M_PI / i;
		cdbl w = cdbl(cos(x),sin(x));
		for(int j=0;j<n;j+=i<<1) {
			cdbl p = cdbl(1,0);
			for(int k=0;k<i;++k) {
				cdbl tmp = a[i+j+k] * p;
				a[i+j+k] = a[j+k] - tmp;
				a[j+k] += tmp;
				p *= w;
			}
		}
	}
	if(inv) {
		for(int i=0;i<n;++i) a[i] /= n;
	}
}

const int N = 1<<21;
int pr[N];

int main(void){
    long long i,j;

    vector<cdbl> a(N,0);
    pr[0]=1;
    pr[1]=1;
    for(i=2; i<=1000000; i++){
        if(pr[i]==1) continue;
        a[i]=1;
        for(j=i*i; j<=1000000; j+=i){
            pr[j]=1;
        }
    }

    fft(a);
    for (i = 0; i < N; i++)
        a[i] *= a[i];
    fft(a, true);
    
    
    int m;
    scanf("%d",&m);
    for(i=0; i<m; i++){
        int x;
        scanf("%d",&x);
        int y = (int)(a[x].real() + 0.5);
        y+=(1-pr[x/2]);
        printf("%d\n",y/2);
    }

    return 0;
}
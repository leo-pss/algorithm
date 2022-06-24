#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <set>

using namespace std;

typedef long long ll;

const ll LLONG_MAX = 1e18;

struct Line { //kx+m;
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	static const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};

const int MAX = 100011;

int n;
ll h[MAX];
ll w[MAX];
ll s[MAX]; //sum
ll d[MAX]; //dp

LineContainer cht;

int main(void){
    int i;

    scanf("%d",&n);
    for(i=1; i<=n; i++) scanf("%lld",&h[i]);
    for(i=1; i<=n; i++){
        scanf("%lld",&w[i]);
        s[i]=s[i-1]+w[i];
    }
    Line tmp;
    cht.add(2*h[1],s[1]-h[1]*h[1]);
    for(i=2; i<=n; i++){
        d[i] = (h[i]*h[i]+s[i-1]) - cht.query(h[i]);
        cht.add(2*h[i],s[i]-h[i]*h[i]-d[i]);     
    }
    printf("%lld",d[n]);
}
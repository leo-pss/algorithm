#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;
const ll INF = 1e18;

struct Dinic {
    ll n;
    struct Edge {
        ll v, cap, rev;
        Edge(ll v, ll cap, ll rev) :v(v), cap(cap), rev(rev) {}
    };
    vector<vector<Edge>> vt;
    void addEdge(ll s, ll e, ll c) {
        vt[s].emplace_back(e, c, vt[e].size());
        vt[e].emplace_back(s, 0, vt[s].size() - 1);
    }
    vector<ll> level, work;
    Dinic(ll n) :n(n) {
        vt.resize(n + 1);
        level.assign(n + 1, -1);
        work.assign(n + 1, 0);
    }
    bool bfs(ll src, ll sink) {
        level.assign(n + 1, -1);
        queue<ll> q;
        level[src] = 0;
        q.push(src);
        while (q.size()) {
            ll here = q.front(); q.pop();
            for (auto i : vt[here]) {
                if (i.cap > 0 && level[i.v] == -1) {
                    level[i.v] = level[here] + 1;
                    q.push(i.v);
                }
            }
        }
        return level[sink] != -1;
    }
    ll dfs(ll sink, ll here, ll crtcap) {
        if (sink == here)return crtcap;
        for (ll &i = work[here]; i < vt[here].size(); i++) {
            ll cap = vt[here][i].cap;
            ll there = vt[here][i].v;
            if (level[here] + 1 == level[there] && cap>0) {
                ll c = dfs(sink, there, min(crtcap, cap));
                if (c) {
                    vt[here][i].cap -= c;
                    vt[there][vt[here][i].rev].cap += c;
                    return c;
                }
            }
        }
        return 0;
    }
    ll solve(ll src, ll sink) {
        ll ret = 0;
        while (bfs(src, sink)) {
            work.assign(n + 1, 0);
            while (1) {
                ll flow = dfs(sink, src, INF);
                if (!flow)break;
                ret += flow;
            }
        }
        return ret;
    }
};

ll a[211],b[211];
ll d[211][211];

int main(void){
    ll n,m,i,j,k,x,y,z,fl=0;

    scanf("%lld %lld",&n,&m);
    fill(&d[0][0],&d[210][210],INF);    
    for(i=1; i<=n; i++){
        scanf("%lld %lld",&a[i],&b[i]);
        d[i][i]=0;
        fl+=a[i];
    }
    for(i=1; i<=m; i++){
        scanf("%lld %lld %lld",&x,&y,&z);
        d[x][y]=min(d[x][y],z);
        d[y][x]=min(d[y][x],z);
    }
    for(k=1; k<=n; k++){
	    for(i=1; i<=n; i++){
		    for(j=1; j<=n; j++){
			    d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
		    }
	    }
    }
    ll l=0,r=2000000000000,w;
    int nn=2*n+3;
    while(l<=r){
        w=(l+r)/2;
        Dinic di(nn);
        for(i=1; i<=n; i++){
            di.addEdge(nn-2,i,a[i]);
            di.addEdge(i,i+n,INF);
            di.addEdge(i+n,nn-1,b[i]);
            for(j=i+1; j<=n; j++){
                if(d[i][j]<=w && d[i][j]!=INF){
                    di.addEdge(i,j+n,INF);
                    di.addEdge(j,i+n,INF);
                }
            }
        }
        ll result = di.solve(nn-2,nn-1);
        if(result==fl) r=w-1;
        else l=w+1;
    }
    if(l>2000000000000) printf("-1");
    else printf("%lld",l);

    return 0;
}
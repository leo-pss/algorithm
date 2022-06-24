#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;
const int INF = 1e9;

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

int m,n;
int c[211][211],cm[211][211];
int csum[211],csumm[211],rsum[211],rsumm[211];

int main(void){
    int i,j,k,x,y,z,w;

    scanf("%d %d",&m,&n);
	int d=m*n*2+m+n+5;
	int S=d-4,E=d-3,s=d-2,e=d-1;
	Dinic D(d);
	D.addEdge(E,S,INF);
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			scanf("%d.%1d",&x,&y);
			w=2*(i*n+j);
			z=2*m*n+m+j;
			D.addEdge(w,e,x);
			D.addEdge(s,w+1,x);
			if(y==0) D.addEdge(w,w+1,0);
			else D.addEdge(w,w+1,1);
			D.addEdge(w+1,z,INF);
			c[i][j]=x; cm[i][j]=(y==0?0:1);
		}
		scanf("%d.%1d",&x,&y);
		rsum[i]=x; rsumm[i]=(y==0?0:1);
		int w=2*m*n+i;
		D.addEdge(S,e,x);
		D.addEdge(s,w,x);
		if(y==0) D.addEdge(S,w,0);
		else D.addEdge(S,w,1);
		for(j=0; j<n; j++){
			z=2*(i*n+j);
			D.addEdge(w,z,INF);
		}
	}
	for(i=0; i<n; i++){
		scanf("%d.%1d",&x,&y);
		csum[i]=x; csumm[i]=(y==0?0:1);
		int w=2*m*n+m+i;
		D.addEdge(w,e,x);
		D.addEdge(s,E,x);
		if(y==0) D.addEdge(w,E,0);
		else D.addEdge(w,E,1);
	}

    int result = D.solve(s,e);
	int ans[211][211];
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			for(auto p : D.vt[2*(i*n+j)]){
				if(p.v == 2*(i*n+j)+1) ans[i][j]=c[i][j]+cm[i][j]-p.cap;
			}
		}
	}
	
	for(auto p : D.vt[S]){
		x=p.v-2*m*n;	
		if(x>=0 && x<m) ans[x][n]=rsum[x]+rsumm[x]-p.cap;
	}
	for(i=0; i<n; i++){
		x=2*m*n+m+i;
		for(auto p : D.vt[x]){
			if(p.v==E) w=p.cap;
		}
		ans[m][i]=csum[i]+csumm[i]-w;
	}
	for(i=0; i<=m; i++){
		for(j=0; j<=n; j++){
			if(i==m && j==n) continue;
			printf("%d ",ans[i][j]);
		}
		printf("\n");
	}

    return 0;
}
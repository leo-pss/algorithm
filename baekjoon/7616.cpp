#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

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
    void print(){
        int node = 2;
        while((node+1)/2 != 2){
            if(node%2==0) printf("%d ", node/2);
            if(node%2==1){
                node = node + 1; continue;
            }
            for(int i=0; i<vt[node].size(); i++){
                int next = vt[node][i].v;
                if((next+1)/2 == (node+1)/2) continue;
                if(vt[node][i].cap == 0){
                    vt[node][i].cap = 1;
                    node = next;
                    break;
                }
            }
        }
        printf("%d\n", 2);
    }
};

int main(void){
    int i,j,tc=0;

    while(1){
        int n,k,y;
        string x;

        scanf("%d %d",&k,&n);
        if(k==0 && n==0) break;

        Dinic D(n*2);
		getline(cin,x);
		for(i=1; i<=n; i++){
			getline(cin,x);
			y=0;
			for(j=0; j<x.size(); j++){
				if(x[j]==' '){
					D.addEdge(i*2,y*2-1,1);
					D.addEdge(y*2,i*2-1,1);
					y=0;
				}
				else{
					y*=10;
					y+=(x[j]-'0');
				}
			}

			D.addEdge(i*2,y*2-1,1);
			D.addEdge(y*2,i*2-1,1);

			D.addEdge(i*2-1,i*2,1);
		}

        printf("Case %d:\n",++tc);
        if(D.solve(2,3)<k){
            printf("Impossible\n");
        }
        else{
            for(i=0; i<k; i++) D.print();
        }
        printf("\n");
    }
}

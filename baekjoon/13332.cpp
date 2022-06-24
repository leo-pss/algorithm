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

int m,n,p,pp;

struct va{
    int day,d1,d2;
};
vector<va> vac[111];

int main(void){
    int i,j,k,x,y,z,w;

    scanf("%d %d %d %d",&m,&n,&p,&pp);
    int d=21*m+n+5;
    int S=d-4, E=d-3;
    int s=d-2, e=d-1;
    Dinic D(d);
    D.addEdge(E,S,INF);
    int low_sum=0;

    //직원 : 1~m
    //각 직원의 휴가 스케줄 : m+20*(i-1)+1~20
    //휴가 : 21*m+1~n
    for(i=1; i<=n; i++){
        scanf("%d %d",&x,&y);

        //각 휴가->싱크로 m-q'/m-q 간선 생성
        D.addEdge(21*m+i,e,m-y);
        D.addEdge(s,E,m-y);
        D.addEdge(21*m+i,E,y-x);
        low_sum+=(m-y);
    }
    for(i=1; i<=m; i++){
        //소스->각 직원 n-p'/n-p 간선 생성
        D.addEdge(S,e,n-pp);
        D.addEdge(s,i,n-pp);
        D.addEdge(S,i,pp-p);
        low_sum+=(n-pp);

        scanf("%d",&w);
        for(j=1; j<=w; j++){
            scanf("%d %d %d",&x,&y,&z);
            vac[i].push_back({x,y,z});
            int ww=m+20*(i-1)+j;

            //각 직원->각 직원의 휴가스케줄 dj/rj'-rj+1 간선 생성
            D.addEdge(i,e,x);
            D.addEdge(s,ww,x);
            D.addEdge(i,ww,z-y+1-x);
            low_sum+=x;
            for(k=y; k<=z; k++){
                D.addEdge(ww,21*m+k,1);
            }
        }
    }
    int result = D.solve(s,e);
    if(result!=low_sum){
        printf("-1");
        return 0;
    }
    printf("1\n");
    vector<int> ans[111];
    for(i=1; i<=m; i++){
        for(j=0; j<vac[i].size(); j++){
            int ww=m+20*(i-1)+j+1;
            y=vac[i][j].d1;
            z=vac[i][j].d2;
            for(k=y; k<=z; k++){
                for(auto p : D.vt[ww]){
                    if(p.v==21*m+k && p.cap==0){
                        ans[i].push_back(k);
                    }
                }
            }
        }
        sort(ans[i].begin(),ans[i].end());
        printf("%d ",ans[i].size());
        for(auto p : ans[i]){
            printf("%d ",p);
        }
        printf("\n");
    }

    return 0;
}
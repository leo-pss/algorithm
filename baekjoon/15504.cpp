#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 300;
const int MAX_V = 2*MAX_N+3;
const int S = MAX_V-1;
const int E = MAX_V-2;
const int INF = 1e9;

struct Edge{
	int to,c,f,d;
	Edge *dual;
	Edge() : Edge(-1,0,0){}
	Edge(int to1,int c1,int d1) : to(to1),c(c1),f(0),d(d1),dual(nullptr){}
	int spare(){ return c-f; }
	void addFlow(int f1){
		f+=f1;
		dual->f-=f1;
	}
};

vector<Edge*> adj[MAX_V];

int n;
int A[MAX_V],H[MAX_V],L[MAX_V];

void make(int u,int v,int c1,int d1,int c2,int d2){ //u->v : c1,d1 | v->u : c2,d2
	Edge *e1 = new Edge(v,c1,d1), *e2 = new Edge(u,c2,d2);
	e1->dual=e2;
	e2->dual=e1;
	adj[u].push_back(e1);
	adj[v].push_back(e2);

}
int main() {
	int i,j,x,y;
    int mmax=0;

	scanf("%d",&n);
    for(i=1; i<=n; i++){
        scanf("%d",&A[i]);
        if(mmax<A[i]){
            mmax=A[i];
            y=i;
        }
    }
    for(i=1; i<=n; i++) scanf("%d",&H[i]);
    for(i=1; i<=n; i++) scanf("%d",&L[i]);
    for(i=1; i<=n; i++){
        if(i!=y){
            make(S,i*2-1,1,0,0,0);
            make(i*2,E,L[i]-1,0,0,0);
        }
        else{
            make(i*2,E,L[i],0,0,0);
        }
        for(j=1; j<=n; j++){
            if(i==j) continue;
            if(A[i]<A[j]){
                x = (A[i]^A[j]) - (H[i]+H[j]);
                //printf("%d %d : %d\n",i,j,x);
                make(i*2-1,j*2,1,-x,0,x);
            }
        }
    }
	
	long long total=0,result=0;
	while(1){
		int prev[MAX_V],dist[MAX_V];
		Edge *path[MAX_V]={0};
		bool inQ[MAX_V]={0};
		queue<int> Q;
		
		fill(prev,prev+MAX_V,-1);
		fill(dist,dist+MAX_V,INF);
		Q.push(S);
		dist[S]=0; inQ[S]=true;
		while(!Q.empty()){
			int curr=Q.front(); Q.pop(); inQ[curr]=false;
			for(Edge *e : adj[curr]){
				int next = e->to;
				if(e->spare()>0 && dist[next]>dist[curr]+e->d){
					dist[next]=dist[curr]+e->d;
					prev[next]=curr;
					path[next]=e;
					if(!inQ[next]){
						Q.push(next);
						inQ[next]=true;
					}
					if(next==E) break;
				}
			}
		}
		if(prev[E]==-1) break;
		
		int flow = INF;
		for(i=E; i!=S; i=prev[i]){
			flow = min(flow,path[i]->spare());
		}
		for(i=E; i!=S; i=prev[i]){
			result+=flow*path[i]->d;
			path[i]->addFlow(flow);
		}
		total+=flow;
	}
	printf("%lld",-result);
	
	return 0;
}

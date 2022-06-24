#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 100;
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

int n,p;

void make(int u,int v,int c1,int d1,int c2,int d2){ //u->v : c1,d1 | v->u : c2,d2
	Edge *e1 = new Edge(v,c1,d1), *e2 = new Edge(u,c2,d2);
	e1->dual=e2;
	e2->dual=e1;
	adj[u].push_back(e1);
	adj[v].push_back(e2);
}

int main() {
	int i,j,k,x;
	int c[MAX_V][MAX_V];
	
	scanf("%d %d",&n,&p);
	for(i=1; i<n; i++){
        for(j=i+1; j<=n; j++){
            scanf("%d",&c[i][j]);
        }
	}
	for(i=1; i<n; i++){
        make(i,i+1,INF,0,0,0);
        for(j=i+1; j<=n; j++){
            scanf("%d",&x);
            make(i,j,c[i][j],-x,0,x);
        }
	}
    make(S,1,p,0,0,0);
    make(n,E,p,0,0,0); //min cut max flow = p
	
	int total=0,result=0;
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
	printf("%d",-result);
	
	return 0;
}

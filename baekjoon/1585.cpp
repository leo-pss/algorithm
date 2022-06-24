#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 50;
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
vector<Edge*> adj2[MAX_V];

int n,m;

void make(int u,int v,int c1,int d1,int c2,int d2){ //u->v : c1,d1 | v->u : c2,d2
	Edge *e1 = new Edge(v,c1,d1), *e2 = new Edge(u,c2,d2);
	e1->dual=e2;
	e2->dual=e1;
	adj[u].push_back(e1);
	adj[v].push_back(e2);
}

void make2(int u,int v,int c1,int d1,int c2,int d2){ //u->v : c1,d1 | v->u : c2,d2
	Edge *e1 = new Edge(v,c1,d1), *e2 = new Edge(u,c2,d2);
	e1->dual=e2;
	e2->dual=e1;
	adj2[u].push_back(e1);
	adj2[v].push_back(e2);
}

int main() {
	int i,j,x,y,z,T,F;
    int car_in[MAX_V],car_out[MAX_V];
	
	scanf("%d",&n);
	for(i=1; i<=n; i++){
		scanf("%d",&car_in[i]);
		make(S,i,1,0,0,0);
		make2(S,i,1,0,0,0);
	}
	for(i=1; i<=n; i++){
		scanf("%d",&car_out[i]);
		make(i+n,E,1,0,0,0);
		make2(i+n,E,1,0,0,0);
	}
    scanf("%d\n%d",&T,&F);
    for(i=1; i<=n; i++){
        for(j=1;j<=n; j++){
            x=car_in[i]; y=car_out[j];
            if(x<y){
                if(y-x>=T){
                    make(i,j+n,1,0,0,0);
                    make2(i,j+n,1,0,0,0);
                }
                else{
                    z=(T-y+x)*(T-y+x);
                    if(z>=F) z=F;
                    make(i,j+n,1,z,0,-z);
                    make2(i,j+n,1,-z,0,z);
                }
            }
        }
    }
	
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
    if(total<n){
        printf("-1");
        return 0;
    }
	printf("%d ",result);


    total=0; result=0;
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
			for(Edge *e : adj2[curr]){
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

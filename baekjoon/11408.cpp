#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int MAX_N = 400;
const int MAX_V = 2*MAX_N+3;
const int S = MAX_V-1;
const int E = MAX_V-2;
const int INF = 1e9;

int N,M;
int c[MAX_V][MAX_V];
int f[MAX_V][MAX_V];
int d[MAX_V][MAX_V];
vector<int> adj[MAX_V];

int main() {
	int i,j,x,y,z;
	
	scanf("%d %d",&N,&M);
	for(i=1; i<=N; i++){
		scanf("%d",&x);
		for(j=0; j<x; j++){
			scanf("%d %d",&y,&z); y+=MAX_N;
			d[i][y]=z;
			d[y][i]=-z;
			c[i][y]=INF;
			adj[i].push_back(y);
			adj[y].push_back(i);
		}
		c[S][i]=1;
		adj[S].push_back(i);
		adj[i].push_back(S);
	}
	for(i=MAX_N+1; i<=MAX_N+M; i++){
		c[i][E]=1;
		adj[E].push_back(i);
		adj[i].push_back(E);
	}
	
	int total=0,result=0; //최대 유량, 최소 비용
	while(1){
		int prev[MAX_V],dist[MAX_V];
		bool inQ[MAX_V]={0};
		queue<int> Q;
		
		fill(prev,prev+MAX_V,-1);
		fill(dist,dist+MAX_V,INF);
		Q.push(S);
		dist[S]=0;
		inQ[S]=true;
		while(!Q.empty()){
			int curr = Q.front(); Q.pop();
			inQ[curr]=false;
			for(int next : adj[curr]){
				if(c[curr][next]-f[curr][next]>0 && dist[next]>dist[curr]+d[curr][next]){
					dist[next]=dist[curr]+d[curr][next];
					prev[next]=curr;
					if(!inQ[next]){
						Q.push(next);
						inQ[next]=true;
					}
				}
			}
		}
		if(prev[E]==-1) break;
		
		int flow = INF;
		for(i=E; i!=S; i=prev[i]){
			flow = min(flow,c[prev[i]][i]-f[prev[i]][i]);
		}
		total+=flow;
		for(i=E; i!=S; i=prev[i]){
			result += flow * d[prev[i]][i];
			f[prev[i]][i] += flow;
			f[i][prev[i]] -= flow;
		}
	}
	printf("%d\n%d",total,result);
	return 0;
}
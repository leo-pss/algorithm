#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX_V = 203;
const int S = MAX_V-2;
const int E = MAX_V-1;
const int INF = 1e9;

int n, m;
int c[MAX_V][MAX_V], f[MAX_V][MAX_V];
int l[MAX_V][MAX_V]; //각 간선의 lower bound
int demand[MAX_V]; //각 정점의 demand
int level[MAX_V]; //레벨 그래프에서 정점의 레벨
int work[MAX_V]; //dfs중 탐색 불가한 간선 재탐색을 막기 위해 몇번째까지 탐색했는지 기억
vector<vector<int> > adj;
pair<int,int> way[1011];

bool bfs(){ //디닉 bfs
	fill(level,level+MAX_V,-1);
	level[S]=0;
	
	queue<int> Q;
	Q.push(S);
	while(!Q.empty()&&level[E]==-1){
		int curr = Q.front(); Q.pop();
		for(int next : adj[curr]){
			//레벨값이 설정되지 않았고 용량 남으면 이동
			if(level[next]==-1 && c[curr][next]-f[curr][next]>0){
				level[next]=level[curr]+1;
				Q.push(next);
			}
		}
	}
	return level[E]!=-1;
}

int dfs(int curr, int dest, int flow){ //디닉 dfs, curr부터 dest까지 최대 flow만큼의 유량을 보낼 것
	if(curr==dest) return flow;
	
	//현재 정점에서 인접한 곳 탐색
	//이번 단계에서 쓸모없다고 판단한 간선은 저장 후 다시 탐색 X
	for(int &i=work[curr]; i<adj[curr].size(); i++){
		int next=adj[curr][i];
		if(level[next]==level[curr]+1 && c[curr][next]-f[curr][next]>0){
			//df : flow와 다음 dfs함수 값 중 최소값
			int df = dfs(next,dest,min(c[curr][next]-f[curr][next],flow));
			//증가 경로가 있다면 유량 df만큼 흘리고 종료
			if(df>0){
				f[curr][next]+=df;
				f[next][curr]-=df;
				return df;
			}
		}
	}
	return 0;
}

int main() {
	int i,j,t,x,y,z,w;

    adj.resize(MAX_V+1);

    scanf("%d %d",&n,&m);
	for(i=1; i<=n; i++){
		scanf("%d",&x);
        demand[i]=-x;
	}	
    for(i=1; i<=m; i++){
		scanf("%d %d %d %d",&x,&y,&z,&w);
        c[x][y]=w-z; adj[x].push_back(y); adj[y].push_back(x);
        l[x][y]=z;
        demand[x]+=z; demand[y]-=z;
        way[i]={x,y};
	}
    int S_minus=0,S_plus=0;
    for(i=1; i<=n; i++){
        if(demand[i]<0){
          c[S][i]=-demand[i]; adj[S].push_back(i); adj[i].push_back(S);    
          S_minus+=(-demand[i]);
        }
        else if(demand[i]>0){
          c[i][E]=demand[i]; adj[i].push_back(E); adj[E].push_back(i);       
          S_plus+=demand[i];
        }
    }
    if(S_minus != S_plus){ //음수 demand합과 양수 demand합이 다름
        printf("-1");
        return 0;
    }
    
    int total = 0;
    while(bfs()){
        memset(work,0,sizeof(work));
        while(1){
            int flow = dfs(S,E,INF);
            if(flow==0) break;
            total+=flow;
        }
    }
    if(total != S_plus){ //총 유량이 deemand와 다름
        printf("-1");
        return 0;
    }
    
    printf("1\n");
    for(i=1; i<=m; i++){
        x=way[i].first, y=way[i].second;
        printf("%d\n",f[x][y]+l[x][y]);
    }

	return 0;
}

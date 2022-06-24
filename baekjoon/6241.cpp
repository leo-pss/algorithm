#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX_V = 403;
const int S = MAX_V-2;
const int E = MAX_V-1;
const int INF = 1e9;

int n, F, D;
int c[MAX_V][MAX_V], f[MAX_V][MAX_V];
int level[MAX_V]; //레벨 그래프에서 정점의 레벨
int work[MAX_V]; //dfs중 탐색 불가한 간선 재탐색을 막기 위해 몇번째까지 탐색했는지 기억
vector<vector<int> > adj;

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

void make(int e1,int e2, int d){
    c[e1][e2]=d;
    adj[e1].push_back(e2);
    adj[e2].push_back(e1);
}
int main() {
	int i,j,t,x,y,z;
    int check=0;
    int p[MAX_V]={0};

    adj.resize(MAX_V+1);
    scanf("%d %d %d",&n,&F,&D);
    for(i=1; i<=F; i++) make(S,i,1);
    for(i=301; i<=300+D; i++) make(i,E,1);
    for(i=1; i<=n; i++){
        scanf("%d %d",&x,&y);
        make(100+i,200+i,1);
        for(j=1; j<=x; j++){
            scanf("%d",&z);
            make(z,100+i,1);
        }
        for(j=1; j<=y; j++){
            scanf("%d",&z);
            make(200+i,300+z,1);
        }
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

    printf("%d",total);
    
	return 0;
}

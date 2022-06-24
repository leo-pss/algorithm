#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int n,m;
int parent[100011][21];
int dist[100011];
int energy[100011];
vector<pair<int,int> > adj[100011];

void bfs(void){
    int ty;
    queue<int> Q;

    Q.push(1);
    dist[1]=0;
    while(!Q.empty()){
        ty=Q.front(); Q.pop();
        for(auto p : adj[ty]){
            int next = p.first, dis = p.second;
            if(dist[next]==-1){
                dist[next]=dist[ty]+dis;
                parent[next][0]=ty;
                Q.push(next);
            }
        }
    }

}

int main(void){
    int i,j;

    scanf("%d",&n);
    for(i=1; i<=n; i++){
        scanf("%d",&energy[i]);
    }
    for(i=1; i<n; i++){
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        adj[x].push_back({y,z});
        adj[y].push_back({x,z});
    }

    memset(parent,-1,sizeof(parent));
    memset(dist,-1,sizeof(dist));

    bfs();

	for(j=1; j<=18; j++){
		for(i=2; i<=n; i++){
			if(parent[i][j-1]!=-1) parent[i][j]=parent[parent[i][j-1]][j-1];
		}
	}
    for(i=1; i<=n; i++){
        int now = i, d = energy[i];
        for(j=18; j>=0; j--){
            int x = parent[now][j];
            if(x==-1) continue;
            int y = abs(dist[now]-dist[x]);
            if(y>d) continue;
            now = x, d-=y;
        }
        printf("%d\n",now);
    }

}
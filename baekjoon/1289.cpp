#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;
const int MAX_N = 100001;
int n;
int d[MAX_N];
int s[MAX_N];
vector<pair<int,int> > adj[MAX_N];

void dfs(int curr,int prev){ //현재 노드, 부모노드
	int temp=0, vcnt=0;
	
	//d[u] : u를 루트로 하는 트리의 가중치
    //s[u] : u를 루트로 하는 트리에서 u와 나머지 노드간의 경로의 가중치의 합
	for(auto p : adj[curr]){
        int next = p.first, w = p.second;
		if(next==prev) continue; //부모면 skip
		
		dfs(next,curr); //next의 dp값을 계산
        int z = (1LL * (s[next] + 1) * w) % MOD;
		s[curr]=(s[curr] + z) % MOD;

        vcnt++;
		if(vcnt==1){ //처음 뽑을 경우
			temp = z;  
            d[curr]=(d[curr] + d[next]) % MOD;
		}
		else{
            d[curr] = (d[curr] + d[next] + 1LL * temp * z) % MOD;
            temp=(temp + z) % MOD;
		}
	}
    d[curr] = (d[curr] + s[curr]) % MOD;
}
int main() {
	int i;
	
	scanf("%d",&n);
	for(i=1; i<n; i++){
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	dfs(1,0);

	printf("%d",d[1]);
	return 0;
}
#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int,int> P;
int n,m,k;
pair<int,P> adj[100001];
int uf[1001];
int e[1001];

int find(int a){
	if(uf[a]<0) return a;
	return uf[a] = find(uf[a]);
}

void merge(int a, int b){
	a = find(a);
	b = find(b);
	uf[b] = a;
    if(e[a]==1 || e[b]==1){
        e[a]=1; e[b]=1;
    }
}

int main() {
	int i,j,x,y,z;
	
	scanf("%d %d %d",&n,&m,&k);
    for(i=1; i<=k; i++){
        scanf("%d",&x);
        e[x]=1;
    }
    
	for(i=1; i<=m; i++){
		scanf("%d %d %d",&x,&y,&z);
		adj[i].first = z;
		adj[i].second.first = x;
		adj[i].second.second = y;
	}
	sort(adj+1,adj+m+1);
	int result = 0;
	fill(uf+1,uf+n+1,-1);
	for(i=1; i<=m; i++){
		x = adj[i].second.first;
		y = adj[i].second.second;
		z = adj[i].first;
        int fx=find(x), fy=find(y);
        if(e[fx]==1 && e[fy]==1) continue;
        if(fx==fy) continue;
        merge(x,y);
		result+=z;
	}
	printf("%d",result);
	
	return 0;
}

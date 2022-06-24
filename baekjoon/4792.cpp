#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int,int> P;
int n,m,k;
pair<int,P> adj[500011];
int uf[1011];

int find(int a){
	if(uf[a]<0) return a;
	return uf[a] = find(uf[a]);
}

bool merge(int a, int b){
	a = find(a);
	b = find(b);
	if(a==b) return false;
	uf[b] = a;
	return true;
}

int main() {
    ios_base :: sync_with_stdio(false); 
cin.tie(NULL); 
cout.tie(NULL);

	int i,j,x,y,z;
    char w;
	
	while(1){
        cin >> n >> m >> k;
        if(n==0 && m==0 && k==0) break;
        for(i=1; i<=m; i++){
            cin >> w >> y >> z;
            if(w=='B') adj[i].first=1;
            else adj[i].first=0;
            adj[i].second.first = y;
            adj[i].second.second = z;
        }
        sort(adj+1,adj+m+1);
        int result = 0, cnt = 0;
        fill(uf,uf+n+1,-1);
        for(i=1; ; i++){
            x = adj[i].second.first;
            y = adj[i].second.second;
            z = adj[i].first;
            if(merge(x,y)){
                result+=z;
                if(++cnt==n-1) break;
            }
        }
        for(i=1; i<=m; i++) adj[i].first=-adj[i].first;
        sort(adj+1,adj+m+1);
        int result2 = 0; cnt = 0;
        fill(uf+1,uf+n+1,-1);
        for(i=1; ; i++){
            x = adj[i].second.first;
            y = adj[i].second.second;
            z = adj[i].first;
            if(merge(x,y)){
                result2+=z;
                if(++cnt==n-1) break;
            }
        }
        result2=-result2;
        cout << (result<=k && k<=result2) << "\n";
    }
	return 0;
}

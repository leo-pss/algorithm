#include <iostream>
#include <algorithm>

using namespace std;

struct edge{
    int x,y,cost;
    bool operator<(const edge &E)const{
        return cost<E.cost;
    } 
};

edge e[50011];
int n,m,b,c;
int uf[1011];

int find(int a){
	if(uf[a]<0) return a;
	return uf[a] = find(uf[a]);
}

int main() {
	int i,j,x,y,z;
	
	scanf("%d %d",&n,&m);
    scanf("%d %d",&b,&c);
	for(i=1; i<=m; i++){
		scanf("%d %d %d",&e[i].x,&e[i].y,&e[i].cost);
	}
	sort(e+1,e+m+1);
	fill(uf,uf+n+1,-1);
    int result=0;
	for(i=m; i>=1; i--){
		x = find(e[i].x);
		y = find(e[i].y);
        if(x!=y) uf[x]=y;
        if(find(b)==find(c)){
            result = e[i].cost;
            break;
        }
	}
	printf("%d",result);
	
	return 0;
}

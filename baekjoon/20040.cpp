#include <iostream>
#include <algorithm>

using namespace std;

int n,m;
int uf[500001];

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
	int i,j,x,y,z;
	
	scanf("%d\n%d",&n,&m);
	fill(uf+1,uf+n+1,-1);
	for(i=1; i<=m; i++){
		scanf("%d %d",&x,&y);
        if(!merge(x+1,y+1)){
            printf("%d",i);
            return 0;
        }
	}
    printf("0");
	
	return 0;
}
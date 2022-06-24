#include <iostream>
#include <algorithm>

using namespace std;

struct frog{
    int x1,x2,idx;
};

frog f[100002];
int n,m;
int uf[100002];

int find(int a){
	if(uf[a]==a) return a;
	return uf[a] = find(uf[a]);
}

void merge(int a, int b){
	a = find(a);
	b = find(b);
	uf[b] = uf[a];
}

int main() {
	int i,j,x,y;
	
	scanf("%d %d",&n,&m);
	for(i=1; i<=n; i++){
		scanf("%d %d %d",&f[i].x1,&f[i].x2,&x);
        uf[i]=i;
        f[i].idx=i;
	}
    sort(f+1,f+n+1, [](auto &p, auto &q){
        return p.x1<q.x1;
    });

    for(i=2; i<=n; i++){
        if(f[i].x1<=f[i-1].x2){
            merge(f[i-1].idx,f[i].idx);
            f[i].x2=max(f[i].x2,f[i-1].x2);
        }
    }

    for(i=1; i<=m; i++){
        scanf("%d %d",&x,&y);
        if(find(x)==find(y)) printf("1\n");
        else printf("0\n");
    }
	
	return 0;
}
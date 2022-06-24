#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n,m;
int a[100001];
int answer;

int find(int p){
    if(p==a[p]) return p;
    return a[p]=find(a[p]);
}
int main(void){
    int i;

    scanf("%d\n%d",&n,&m);
    for(i=1; i<=n; i++) a[i]=i;
    for(i=1; i<=m; i++){
        int x,y;
        scanf("%d",&x);
        y=find(x);
        if(y==0) break;
        a[y]=y-1;
        answer++;
    }
    printf("%d",answer);
}
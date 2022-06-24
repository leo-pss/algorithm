#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 1e9;
int n,m;
int a,b,x,y;
int ladder[511];
int d[511][111];

int main(void){
    int i,j,k;

    //입력
    scanf("%d %d",&n,&m);
    scanf("%d %d %d %d",&a,&b,&x,&y);
    for(i=1; i<=m; i++) scanf("%d",ladder+i);

    //초기화
    for(i=0; i<=m; i++){
        for(j=1; j<=n; j++){
            d[i][j]=INF;
        }
    }
    for(i=1; i<=n; i++){
        if(i==a) d[0][i]=0;
        else d[0][i] = abs(i-a)*y;
    }

    //dp 구현
    //d[i][j] : i번째 사다리 이후에 a->j로 조작하는 최소 비용
    for(i=1; i<=m; i++){
        for(j=1; j<=n; j++){
            for(k=1; k<=n; k++){
                if(j==k && (ladder[i]==k || ladder[i]+1==k)){
                    if(d[i][j]>d[i-1][k]+x) d[i][j] = d[i-1][k]+x;
                }
                else if((k<=ladder[i] && ladder[i]+1<=j) || (j<=ladder[i] && ladder[i]+1<=k)){
                    if(d[i][j]>d[i-1][k]+(abs(k-j)-1)*y) d[i][j]=d[i-1][k]+(abs(k-j)-1)*y;
                }
                else{
                    if(d[i][j]>d[i-1][k]+abs(k-j)*y) d[i][j] = d[i-1][k]+abs(k-j)*y;
                }
            }
        }
    }
    printf("%d",d[m][b]);

    return 0;
}
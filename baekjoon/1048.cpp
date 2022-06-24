#include <iostream>
#include <cstring>
using namespace std;

int n,m,l;
char a[311][311];
long long d[61][311][311],rsum[61][311][311];
char s[311];
const long long MOD = 1000000007;

long long sum(int k,int i,int j){
	if(k==1) return 1;
	long long ret = 0;
	if(i>=3 && j>=3){
		ret=(ret+rsum[k-1][i-2][j-2]+MOD)%MOD;
		ret=(ret-d[k-1][i-3][j-3]+MOD)%MOD;
	}
	if(i+2<=n && j>=3){
		ret=(ret+rsum[k-1][n][j-2]-rsum[k-1][i+1][j-2]+MOD)%MOD;
		ret=(ret-d[k-1][i+1][j-3]+MOD)%MOD;
	}
	if(i>=3 && j+2<=m){
		ret=(ret+rsum[k-1][i-2][m]-rsum[k-1][i-2][j+1]+MOD)%MOD;
		ret=(ret-d[k-1][i-3][j+1]+MOD)%MOD;
	}
	if(i+2<=n && j+2<=m){
		ret=(ret+rsum[k-1][n][m]-rsum[k-1][i+1][m]-rsum[k-1][n][j+1]+2*MOD+rsum[k-1][i+1][j+1])%MOD;
		ret=(ret-d[k-1][i+1][j+1]+MOD)%MOD;
	}
	return ret%MOD;
}
int main() {
	int i,j,k;
	
	scanf("%d %d %d",&n,&m,&l);
	scanf("%s",&s);
	for(i=0; i<n; i++) scanf("%s",&a[i]);
	int K=strlen(s);
	for(k=1; k<=K; k++){
		for(i=0; i<n; i++){
			for(j=0; j<m; j++){
				if(s[k-1]==a[i][j]) d[k][i][j]=sum(k,i+1,j+1);
			}
		}
		for(i=0; i<n; i++){
			for(j=0; j<m; j++){
				rsum[k][i+1][j+1]=(rsum[k][i][j+1]+rsum[k][i+1][j]-rsum[k][i][j]+MOD+d[k][i][j])%MOD;
			}
		}
	}
	printf("%lld",rsum[K][n][m]);
	return 0;
}
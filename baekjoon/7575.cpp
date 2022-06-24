#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> getPartialMatch(const vector<int>& N){
	int m = N.size();
	vector<int> pi(m,0);
	int begin = 1, matched = 0;
	while(begin+matched<m){
		if(N[begin+matched]==N[matched]){
			++matched;
			pi[begin+matched-1]=matched;
		}
		else{
			if(matched==0){
				++begin;
			}
			else{
				begin+=matched-pi[matched-1];
				matched = pi[matched-1];
			}
		}
	}
	return pi;
}

int kmpSearch(const vector<int>& H, const vector<int>& N){
	int n = H.size(), m = N.size();

	vector<int> ret;
	vector<int> pi = getPartialMatch(N);
	int matched = 0;
	for(int i=0; i<n; ++i){
		while(matched>0 && H[i]!=N[matched]){
			matched = pi[matched-1];
		}
		if(H[i] == N[matched]){
			++matched;
			if(matched == m){
                return 1;
				matched = pi[matched-1];
			}
		}
	}
	return -1;
}

int main(void) {
    int i,j,n,k;
    int x,y;

    scanf("%d %d",&n,&k);
    scanf("%d",&x);
    vector<int> A(x,0);
    for(i=0; i<x; i++){
        scanf("%d",&A[i]);
    }
    vector<int> B[101];
    for(i=2; i<=n; i++){
        scanf("%d",&x);
        B[i].resize(2*x+1);
        for(j=0; j<x; j++){
            scanf("%d",&B[i][j]);
            B[i][2*x-j]=B[i][j];
        }
        B[i][x]=-1;
    }
    
    int chk;
    for(i=0; i<A.size()-k+1; i++){
        vector<int> tmp(k,0);
        for(j=0; j<k; j++) tmp[j]=A[j+i];
        chk=1;
        for(j=2; j<=n; j++){
            x=kmpSearch(B[j],tmp);
            if(x==-1) { chk=0; break; }
        }
        if(chk==1){
            printf("YES");
            return 0;
        }
    }
    printf("NO");

    return 0;
}
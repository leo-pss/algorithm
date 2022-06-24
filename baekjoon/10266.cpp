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

vector<int> kmpSearch(const vector<int>& H, const vector<int>& N){
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
				ret.push_back(i-m+1);
				matched = pi[matched-1];
			}
		}
	}
	return ret;
}

int main(void) {
    int i,n,x;

    vector<int> A(720000,0);
    vector<int> B(360000,0);
    scanf("%d",&n);
    for(i=1; i<=n; i++){
        scanf("%d",&x);
        A[x]=1;
        A[x+360000]=1;
    }

    for(i=1; i<=n; i++){
        scanf("%d",&x);
        B[x]=1;
    }

    vector<int> ans = kmpSearch(A,B);

    if(ans.size()==0) printf("impossible");
    else printf("possible");

    return 0;
}
#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> getPartialMatch(const string& N){
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

vector<int> kmpSearch(const string& H, const string& N){
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

int gcd(int x, int y){
    if(y==0){
        return x;
    }
    else{
        return gcd(y,x%y);
    }
}
int main(void) {

    int i,n;
    string A,B;
    char x;

    scanf("%d",&n);
    for(i=0; i<n; i++){
        scanf(" %c",&x);
        A.push_back(x);
    }
    for(i=0; i<n; i++){
        scanf(" %c",&x);
        B.push_back(x);
    }
    B+=B;
    B.pop_back();
    vector<int> ans = kmpSearch(B,A);
    int p=ans.size(), q=n;
    int r=gcd(q,p);
    printf("%d/%d",p/r,q/r);

    return 0;
}
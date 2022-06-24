#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<long long> getPartialMatch(const string& N){
	int m = N.size();
	vector<long long> pi(m,0);
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

int main(void) {
    long long i;
	string A;

    while(1){	    
        cin >> A;
        if(A[0]=='.') break;
        long long n = A.size();
        vector<long long> pi = getPartialMatch(A);
        for(i=n; i>=1; i--){
            if(n%i==0 && pi[n-1]==(n/i)*(i-1)){
                break;
            }
        }
        cout << (i==0?1:i) << "\n";
    }
	return 0;
}
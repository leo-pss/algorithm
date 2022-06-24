#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main(void){
    int t;

    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n;
        cin >> s;
        int m = (n+1)/2;
        int cnt = 0;
        for(int i=m-1; i>=1; i--){
            if(s[i] == s[i-1]){
                cnt++;
            }
            else{
                break;
            }
        }
        if(n%2==0) cout << cnt*2 +2 << "\n";
        else cout << cnt*2 + 1 << "\n";
    }
    return 0;
}
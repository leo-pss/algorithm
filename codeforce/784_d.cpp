#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main(void){
    int i,t;

    cin >> t;
    while(t--){
        int n;
        string a;

        cin >> n;
        cin >> a;
        int r = 0, b = 0;
        int check = 1;
        for(i=0; i<n; i++){
            if(a[i]=='R'){
                ++r;
            }
            if(a[i]=='B'){
                ++b;
            }
            if(a[i]=='W' || i==n-1){
                if(r==0 && b==0) continue;
                else if(r==0 || b==0) check=0;
                r = 0;
                b = 0;
            }
        }

        if(check) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
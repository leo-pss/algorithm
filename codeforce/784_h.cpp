#include <iostream>

using namespace std;

int main(void){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int i,j,t;
    cin >> t;
    while(t--){
        int a[31];
        int n,k,x;
        cin >> n >> k;
        for(i=0; i<=30; i++) a[i]=0;
        for(i=1; i<=n; i++){
            cin >> x;
            for(j=0; j<=30; j++){
                if(x%2) a[j]++;
                x/=2;
                if(x==0) break;
            }
        }
        int answer = 0;
        for(i=30; i>=0; i--){
            if(k>=n-a[i]){
                k-=(n-a[i]);
                answer+=(1<<i);
            }
        }
        cout << answer << "\n";
    }
}
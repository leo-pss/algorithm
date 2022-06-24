#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int i,j,k,t;

    cin >> t;
    while(t--){
        int n,m;
        string a[52];
        char answer[52][52];
        vector<int> s;
        vector<int> o;
        cin >> n >> m;
        for(i=0; i<n; i++){
            cin >> a[i];
            for(j=0; j<m; j++) answer[i][j]='.';
        }
        int cnt;
        for(i=0; i<m; i++){
            cnt = 0;
            for(j=0; j<n; j++){
                if(a[j][i] == '*') cnt++;
                if(a[j][i] == 'o'){
                    s.push_back(cnt);
                    o.push_back(j);
                    cnt = 0;
                }
                else if(j==n-1){
                    s.push_back(cnt);
                    o.push_back(n);
                }
                
            }
            for(j=s.size()-1; j>=0; j--){
                answer[o[j]][i]='o';
                for(k=o[j]-1; k>o[j]-1-s[j]; k--){
                    answer[k][i]='*';
                }
            }
            s.clear();
            o.clear();
        }
        for(i=0; i<n; i++){
            for(j=0; j<m; j++){
                cout<<answer[i][j];
            }
            cout<<"\n";
        }
        cout<<"\n";
    }

    return 0;
}
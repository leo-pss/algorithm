#include <iostream>
#include <string>
using namespace std;

long long first[12][12];
long long second[12][12];

int main(void){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int i, j, k, t;

    cin >> t;
    while(t--){
        for(i=1; i<=11; i++){
            for(j=1; j<=11; j++){
                first[i][j]=0;
                second[i][j]=0;
            }
        }

        int n,a,b;
        string x;
        cin >> n;
        
        for(i=1; i<=n; i++){
            cin >> x;
            a = x[0] - 'a' + 1;
            b = x[1] - 'a' + 1;
            first[a][b]++;
            second[b][a]++;
        }
        long long answer = 0;
        for(i=1; i<=11; i++){
            for(j=1; j<=11; j++){
                for(k=j+1; k<=11; k++){
                    answer += first[i][j] * first[i][k];
                    answer += second[i][j] * second[i][k];
                }
            }
        }
        cout << answer << "\n";
    }

    return 0;
}
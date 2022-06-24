#include <stdio.h>
#include <iostream>

using namespace std;

int a[200002];
int sum1[200002];
int sum2[200002];

int main(void){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int i,t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        sum1[0] = 0;
        for(i=1; i<=n; i++){
            cin >> a[i];
            sum1[i] = sum1[i-1] + a[i];
        }
        sum2[0] = 0;
        for(i=n; i>=1; i--){
            sum2[n-i+1] = sum2[n-i] + a[i];
        }
        int left = 1, right = 1;
        int answer = 0;
        while(left+right<=n){
            if(sum1[left] == sum2[right]){
                answer = answer < left+right ? left+right : answer;
                left++;
                right++;
            }
            else if(sum1[left] > sum2[right]){
                right++;
            }
            else{
                left++;
            }
        }
        cout << answer << "\n";
    }
    return 0;
}
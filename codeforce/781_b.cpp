#include <stdio.h>
#include <algorithm>
#include <cmath>

using namespace std;


int t, n;
int a[100001];

int main(void){
    int i;

    a[0] = 1000000001;
    scanf("%d", &t);
    while(t--){
        scanf("%d",&n);
        for(i=1; i<=n; i++){
            scanf("%d", &a[i]);
        }
        sort(a+1, a+n+1);
        int max_count = 0;
        int count = 1;
        for(i=1; i<=n; i++){
            if(a[i] != a[i-1]){
                max_count = max(max_count, count);
                count = 1;
            }
            else{
                ++count;
            }
        }
        max_count = max(max_count, count);
        int answer = n - max_count;
        while(max_count < n){
            answer++;
            max_count *= 2;
        }
        printf("%d\n", answer);
    }

}
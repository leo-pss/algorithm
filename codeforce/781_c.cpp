#include <stdio.h>
#include <algorithm>
#include <cmath>

using namespace std;


int t, n;
int a[200001];
int child_count[200001];
int over_child[200001];

int main(void){
    int i;

    a[0] = 1000000001;
    scanf("%d", &t);
    while(t--){
        scanf("%d",&n);
        for(i=1; i<n; i++){
            scanf("%d", &a[i]);
        }
        sort(a+1, a+n);
        int count = 1;
        int cnt = 0;

        for(i=1; i<n; i++){
            if(a[i] != a[i-1]){
                child_count[++cnt] = count;
                count = 1;
            }
            else{
                ++count;
            }
        }
        child_count[++cnt] = count;
        sort(child_count+1, child_count+cnt+1);
        int over_parent = 0;
        for(i=1; i<=cnt; i++){
            if(child_count[i]>i){
                ++over_parent;
                over_child[over_parent] = -(child_count[i] - i);
            }
        }
        sort(over_child+1, over_child+over_parent+1);
        int over_cnt = 0;
        int min_child = 0;
        int min_child_i = 0;
        int end = over_parent;
        while(1){
            if(end == 0){
                break;
            }
            ++over_cnt;
            for(i=1; i<=over_parent; ++i){
                ++over_child[i];
                if(over_child[i]==0){
                    --end;
                }
            }
            min_child = 0;
            for(i=1; i<=over_parent; ++i){
                if(min_child > over_child[i]){
                    min_child = over_child[i];
                    min_child_i = i;
                }
            }
            ++over_child[min_child_i];
            if(over_child[min_child_i]==0) --end;
        }
        printf("%d\n",cnt + over_cnt);
    }

}
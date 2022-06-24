#include <iostream>
#include <algorithm>

using namespace std;

int n;
struct T{
    int w,p,idx;
};

T a[1000001];

int main(void){
    int i;

    scanf("%d",&n);
    for(i=1; i<=n; i++){
        int x,y;
        scanf("%d %d",&x,&y);
        a[i].w=x;
        a[i].p=10000-y;
        a[i].idx=i;
    }
    sort(a+1,a+n+1, [](auto &A, auto &B){
        if(A.w*B.p!=B.w*A.p) return A.w*B.p>B.w*A.p;
        return A.idx<B.idx;
    });
    for(i=1; i<=n; i++) printf("%d ",a[i].idx);

}
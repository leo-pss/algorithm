#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int MAX = 200011;

string S;
int n,d;
int sa[MAX],pos[MAX],lcp[MAX];

bool cmp(int i,int j){
    if(pos[i]!=pos[j]) return pos[i]<pos[j];
    i+=d; j+=d;
    return (i<n && j<n) ? (pos[i]<pos[j]) : (i>j);
}

void SA(){
    int i;
    n = S.size();
    for(i=0; i<n; i++) sa[i]=i, pos[i]=S[i];
    for(d=1; ; d*=2){
        sort(sa,sa+n,cmp);
        int tmp[MAX]={0};
        for(i=0; i<n-1; i++) tmp[i+1] = tmp[i] + cmp(sa[i],sa[i+1]);
        for(i=0; i<n; i++) pos[sa[i]]=tmp[i];
        if(tmp[n-1]==n-1) break;
    }
}

void LCP(){
    for(int i=0,k=0; i<n; i++, k=max(k-1,0)){
        if(pos[i]==n-1) continue;
        for(int j=sa[pos[i]+1]; S[i+k]==S[j+k]; k++);
        lcp[pos[i]]=k;
    }
}

int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string A,B;
    int m;

    cin >> A >> B;
    m=A.size();
    S= A+'$'+B;
    SA();
    LCP();
    int ans=0,chk=0;
    for(int i=0; i<n-1; i++){
        if( (sa[i]>=m) != (sa[i+1]>=m) ){
            if(ans<lcp[i]){
                ans=lcp[i];
                chk=sa[i];
            }
        }
    }
    cout << ans << "\n";
    for(int i=0; i<ans; i++) cout << S[chk+i];

    return 0;
}
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

const int MAX = 40011;

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
    int i;

    while(1){
        int m;
        cin >> m;
        if(m==0) break;
        memset(sa,0,sizeof(sa));
        memset(pos,0,sizeof(pos));
        memset(lcp,0,sizeof(lcp));
        cin >> S;
        if(m==1){
            cout << S.size() << " 0\n";
            continue;
        }
        SA();
        LCP();
        int l=0,r=n;
        int chk,po,ansp;
        while(l+1<r){
            int w=(l+r)/2;
            chk=0; po=0; 
            for(i=0; i<n-1; i++){
                if(lcp[i]>=w){
                    chk++;  
                    if(chk>=m-1) po=1;
                }
                else chk=0;
            }
            if(po==1){
                l=w;
            }
            else{
                r=w;
            }
        }
        if(l==0){
            cout << "none\n";
        }
        else{
            int tmp=sa[n-1];
            chk=0, ansp=0;
            for(i=n-2; i>=0; i--){
                if(lcp[i]>=l){
                    chk++;
                    tmp=max(tmp,sa[i]);
                    if(chk>=m-1) ansp=max(ansp,tmp);
                }
                else{
                    tmp=sa[i];
                    chk=0;
                }
            }
            cout << l << " " << ansp << "\n";
        }
    }


    return 0;
}
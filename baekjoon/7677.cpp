#include <iostream>

constexpr int MOD = 10000;
typedef long long ll;

void mMul(ll res[5][5], ll left[5][5], ll right[5][5], int n) {
    ll tmp[5][5] = {0};
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                tmp[i][j] = (tmp[i][j] + left[i][k] * right[k][j]) % MOD;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res[i][j] = tmp[i][j];
        }
    }
}

int main() {
    int n=2;
    ll b;
    
    while(1){
        scanf("%lld", &b);
        if(b==-1) break;
        if(b==0){
            printf("0\n");
            continue;
        }
        b--;
        ll powers[100][5][5] = {0};  // powers[i]: A^i % MOD
        powers[0][0][0]=1;
        powers[0][0][1]=1;
        powers[0][1][0]=1;
        powers[0][1][1]=0;
        for (int i = 1; ((ll)1<<i) <= b; i++) {
            mMul(powers[i], powers[i-1], powers[i-1], n);
        }
        ll k[5][5] = {0};
        for (int i = 0; i < n; i++) k[i][i] = 1;  // 항등행렬
        for (int i = 0; ((ll)1<<i) <= b; i++) {
            if (((ll)1<<i) & b) {
                mMul(k, k, powers[i], n);
            }
        }
	    printf("%d\n",k[0][0]);
    }
}

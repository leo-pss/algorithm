class Solution {
    final long MOD = 1000000007;
    public int numTilings(int n) {
        long[] d = new long[n+3];
        d[0] = 1; d[1] = 1; d[2] = 2; d[3] = 5;
        for(int i = 4; i <= n; i++){
            d[i] = (d[i-1] * 2 + d[i-3]) % MOD;
        }
        return (int)d[n];
    }
}
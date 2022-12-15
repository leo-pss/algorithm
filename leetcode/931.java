class Solution {
    public int minFallingPathSum(int[][] matrix) {
        int n = matrix.length;
        int[][] d = new int[n][n];
        for(int i = 0; i < n; i++) d[0][i] = matrix[0][i];
        for(int i = 1; i < n; i++){
            for(int j = 0; j < n; j++){
                int tmp = d[i-1][j];
                if(j > 0) tmp = Math.min(tmp, d[i-1][j-1]);
                if(j < n-1) tmp = Math.min(tmp, d[i-1][j+1]);
                d[i][j] = tmp + matrix[i][j];
            }
        }
        int answer = 10001;
        for(int i = 0; i < n; i++){
            answer = Math.min(answer, d[n-1][i]);
        }
        return answer;
    }
}
class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        int n = temperatures.length;
        int[] stack = new int[n];
        int[] answer = new int[n];
        int top = -1;
        for(int i = 0; i < n; i++){
            while(top > -1 && temperatures[i] > temperatures[stack[top]]){
                int idx = stack[top--];
                answer[idx] = i - idx;
            }
            stack[++top] = i;
        }
        return answer;
    }
}
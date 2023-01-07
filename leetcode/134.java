class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int n = gas.length;
        int totalSum = 0;
        int sum = 0;
        int answer = 0;

        for(int i = 0; i < n; i++) {
            int gap = (gas[i] - cost[i]);
            totalSum += gap;
            sum += gap;
            if(sum < 0) {
                sum = 0;
                answer = i + 1;
            }
        }
        if(totalSum < 0) return -1;
        return answer;        
    }
}
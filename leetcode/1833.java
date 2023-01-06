class Solution {
    public int maxIceCream(int[] costs, int coins) {
        Arrays.sort(costs);
        int answer = 0;
        for(int cost : costs) {
            if(cost > coins) break;
            coins -= cost;
            answer++;
        }
        return answer;
    }
}
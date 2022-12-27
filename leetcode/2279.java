class Solution {
    public int maximumBags(int[] capacity, int[] rocks, int additionalRocks) {
        int n = capacity.length;
        int answer = 0;
        int space[] = new int[n];
        for(int i = 0; i < n; i++) {
            space[i] = capacity[i] - rocks[i];
        }
        Arrays.sort(space);
        for(int i = 0; i < n; i++){
            if(space[i] > additionalRocks) break;
            answer++;
            additionalRocks -= space[i];
        }

        return answer;
    }
}
class Solution {
    public int[] answerQueries(int[] nums, int[] queries) {
        Arrays.sort(nums);
        int n = nums.length, m = queries.length;
        int[] answer = new int[m];
        for (int i = 1; i < n; ++i) {
            nums[i] += nums[i-1];
        }
        for (int i = 0; i < m; ++i) {
            int lower_bound = Arrays.binarySearch(nums, queries[i]);
            answer[i] = Math.abs(lower_bound + 1);
        }
        return answer;
    }
}
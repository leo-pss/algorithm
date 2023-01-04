class Solution {
    private int getRound(int taskCount) {
        if(taskCount % 3 == 0) return taskCount / 3;
        if(taskCount % 3 == 1) return (taskCount - 4) / 3 + 2;
        return taskCount / 3 + 1;
    }
    public int minimumRounds(int[] tasks) {
        Map<Integer, Integer> taskCountMap = new HashMap<>();
        for(int task : tasks) {
            taskCountMap.put(task, taskCountMap.getOrDefault(task, 0) + 1);
        }
        int answer = 0;
        for (int count : taskCountMap.values()) {
            if(count == 1) return -1;
            answer += getRound(count);
        }
        return answer;
    }
}
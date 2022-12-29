import java.util.Arrays;
import java.util.PriorityQueue;

class Solution {
    public int[] getOrder(int[][] tasks) {
        int n = tasks.length;
        int[][] tasksWithIndex = new int[n][3];
        for(int i = 0; i < n; i++) {
            tasksWithIndex[i] = new int[]{tasks[i][0], tasks[i][1],i};
        }
        Arrays.sort(tasksWithIndex, (a, b)->a[0]-b[0]);
        PriorityQueue<int[]> pq = new PriorityQueue<int[]>((a, b) -> a[1]==b[1] ? a[2]-b[2] : a[1]-b[1]);
        int[] answer = new int[n];
        int index = 0;
        int time = 0;
        int i = 0;
        while(i < n) {
            while(i < n && tasksWithIndex[i][0] <= time) {
                pq.add(tasksWithIndex[i]);
                i++;
            }
            if(pq.isEmpty()){
                time = tasksWithIndex[i][0];
                continue;
            }
            int[] curr_process = pq.poll();
            answer[index] = curr_process[2];
            index++;
            time += curr_process[1];
        }
        while(!pq.isEmpty()){
            int[] curr_process = pq.poll();
            answer[index] = curr_process[2];
            index++;
            time += curr_process[1];
        }

        return answer;
    }
}
import java.util.Collections;
import java.util.PriorityQueue;

class Solution {
    public int minStoneSum(int[] piles, int k) {
        //PriorityQueue<Integer> pq = new PriorityQueue<>((a, b)->b - a);
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        int answer = 0;
        for(int stone : piles) {
            pq.add(stone);
            answer += stone;
        }
        for(int i = 0; i < k; i++) {
            int max_stone = pq.poll();
            pq.add(max_stone - max_stone / 2);
            answer -= max_stone / 2;
        }
        return answer;
    }
}
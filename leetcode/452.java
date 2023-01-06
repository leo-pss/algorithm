class Solution {
    public int findMinArrowShots(int[][] points) {
        Arrays.sort(points, (point1, point2) -> Integer.compare(point1[1], point2[1]));
        int answer = 0;
        int arrow = 0;
        for (int i = 0; i < points.length; i ++) {
            if (answer == 0 || points[i][0] > arrow) {
                answer++;
                arrow = points[i][1];
            }
        }
        return answer;
    }
}
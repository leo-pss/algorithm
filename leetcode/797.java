class Solution {
    private List<List<Integer>> answer = new ArrayList<>();
    private List<Integer> path = new ArrayList<>();
    private int[][] graph;
    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        this.graph = graph;
        path.add(0);
        dfs(0);
        return answer;
    }

    private void dfs(int curr) {
        if(curr == graph.length - 1) {
            answer.add(new ArrayList<Integer>(path));
            return;
        }

        for (int next : graph[curr]) {
            path.add(next);
            dfs(next);
            path.remove(path.size() - 1);
        }
    }
}
class Solution {
    int[] answer;
    int[] child_count;
    List<Set<Integer>> adj;
    public int[] sumOfDistancesInTree(int n, int[][] edges) {
        adj = new ArrayList<Set<Integer>>();
        answer = new int[n];
        child_count = new int[n];
        Arrays.fill(child_count, 1);

        for(int i = 0; i < n; i++){
            adj.add(new HashSet<Integer>());
        }
        for(int[] edge : edges){
            adj.get(edge[0]).add(edge[1]);
            adj.get(edge[1]).add(edge[0]);
        }
        dfs(0, -1);
        dfs2(0, -1);

        return answer;
    }

    public void dfs(int curr, int parent) {
        for(int child : adj.get(curr)){
            if(child != parent){
                dfs(child, curr);
                child_count[curr] += child_count[child];
                answer[curr] += answer[child] + child_count[child];
            }
        }
    }

    public void dfs2(int curr, int parent) {
        for(int child : adj.get(curr)){
            if(child != parent){
                answer[child] = answer[curr] - child_count[child] + child_count.length - child_count[child];
                dfs2(child, curr);
            }
        }
    }
}
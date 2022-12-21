class Solution {
    public boolean bfs(int curr, Map<Integer, List<Integer>> adj, int[] group) {
        Queue<Integer> Q = new LinkedList();
        Q.add(curr);
        group[curr] = 0; 

        while(!Q.isEmpty()){
            int now = Q.remove();
            if(!adj.containsKey(now)) continue;
            for(int next : adj.get(now)) {
                if(group[next] == group[now]) return false;
                if(group[next] == -1) {
                    group[next] = 1 - group[now];
                    Q.add(next);
                }
            }
        }

        return true;
    }
    public boolean possibleBipartition(int n, int[][] dislikes) {
        Map<Integer, List<Integer>> adj = new HashMap<>();
        for(int[] edge : dislikes) {
            int a = edge[0], b = edge[1];
            adj.computeIfAbsent(a, value -> new ArrayList<Integer>()).add(b);
            adj.computeIfAbsent(b, value -> new ArrayList<Integer>()).add(a);
        }

        int[] group = new int[n+1];
        Arrays.fill(group, -1);

        for(int i = 1; i <= n; i++) {
            if(group[i] == -1) {
                if(!bfs(i, adj, group)) {
                    return false;
                }
            }
        }
        
        return true;
    }
}
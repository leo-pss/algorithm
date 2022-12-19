class UnionFind {
    private int[] parent;
    private int N;

    public UnionFind(int n) {
        this.N = n;
        this.parent = new int[this.N];
        for(int i = 0; i < this.N; i++){
            this.parent[i] = i;
        }
    }

    public void union(int u, int v) {
        if(u != v){
            int a = find(u);
            int b = find(v);
            parent[a] = b;
        }
    }

    public int find(int u){
        int x = u;
        while(x != this.parent[x]){
            x = this.parent[x];
        }
        this.parent[u] = x;
        return x;
    }
}

class Solution {
    public boolean validPath(int n, int[][] edges, int source, int destination) {
        UnionFind s = new UnionFind(n);
        for(int[] edge : edges){
            s.union(edge[0], edge[1]);
        }
        return s.find(source) == s.find(destination);
    }
}
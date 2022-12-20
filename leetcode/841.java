class Solution {
    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        Stack<Integer> S = new Stack<>();
        HashSet<Integer> visited = new HashSet<Integer>();

        int n = rooms.size();
        S.add(0);
        visited.add(0);
        while (!S.isEmpty()) {
            int i = S.pop();
            for (int j : rooms.get(i))
                if (!visited.contains(j)) {
                    S.add(j);
                    visited.add(j);
                    if (visited.size() == n) return true;
                }
        }
        return visited.size() == n;
    }
}
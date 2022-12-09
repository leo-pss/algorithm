public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}
class Solution {
    public int maxAncestorDiff(TreeNode root) {
        if(root == null) return 0;
        return solve(root, root.val, root.val);
    }

    public int solve(TreeNode node, int min_val, int max_val){
        if(node == null) return max_val - min_val;
        max_val = Math.max(max_val, node.val);
        min_val = Math.min(min_val, node.val);
        int left = solve(node.left, min_val, max_val);
        int right = solve(node.right, min_val, max_val);
        return Math.max(left, right);
    }
}
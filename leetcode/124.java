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
    int answer;
    public int maxPathSum(TreeNode root) {
        answer = -1000000000;
        solve(root);
        return answer;
    }
    public int solve(TreeNode root){
        if(root == null) return 0;
        int max_path = 0;
        int left_max = solve(root.left);
        int right_max = solve(root.right);
        if(left_max < 0 && right_max < 0) return root.val;
        left_max = Math.max(0, left_max);
        right_max = Math.max(0, right_max);
        max_path = Math.max(0, Math.max(left_max, right_max) + root.val);
        answer = Math.max(answer, root.val + left_max + right_max);
        return max_path;
    }
}
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
    long answer = 0, sum = 0;
    public int maxProduct(TreeNode root) {
        sum = solve(root); solve(root);
        return (int)(answer % (int)(1000000007));
    }
    public long solve(TreeNode root){
        if(root == null) return 0;
        long sub_sum = root.val + solve(root.left) + solve(root.right);
        answer = Math.max(answer, sub_sum * (sum - sub_sum));
        return sub_sum;
    }
}
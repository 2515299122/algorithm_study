//给定二叉搜索树（BST）的根节点
// root 和一个整数值
// val。
//
// 你需要在 BST 中找到节点值等于 val 的节点。 返回以该节点为根的子树。 如果节点不存在，则返回
// null 。
//
//
//
// 示例 1:
//
//
//
//
//
//输入：root = [4,2,7,1,3], val = 2
//输出：[2,1,3]
//
//
// 示例 2:
//
//
//输入：root = [4,2,7,1,3], val = 5
//输出：[]
//
//
//
//
// 提示：
//
//
// 树中节点数在 [1, 5000] 范围内
// 1 <= Node.val <= 10⁷
// root 是二叉搜索树
// 1 <= val <= 10⁷
//
//
// Related Topics 树 二叉搜索树 二叉树 👍 464 👎 0

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode *res = nullptr;

    TreeNode *searchBST(TreeNode *root, int val) {
        if (root == nullptr || root->val == val) return root;
        //当前节点大于目标值，向左遍历
        if (root->val > val) {
            auto left = searchBST(root->left, val);
            if (left && left->val == val) return left;
        }
        if (root->val < val) {
            auto right = searchBST(root->right, val);
            if (right && right->val == val) return right;
        }
        return nullptr;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

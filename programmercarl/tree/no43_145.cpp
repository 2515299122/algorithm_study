//给你一棵二叉树的根节点 root ，返回其节点值的 后序遍历 。
//
//
//
// 示例 1：
//
//
//输入：root = [1,null,2,3]
//输出：[3,2,1]
//
//
// 示例 2：
//
//
//输入：root = []
//输出：[]
//
//
// 示例 3：
//
//
//输入：root = [1]
//输出：[1]
//
//
//
//
// 提示：
//
//
// 树中节点的数目在范围 [0, 100] 内
// -100 <= Node.val <= 100
//
//
//
//
// 进阶：递归算法很简单，你可以通过迭代算法完成吗？
//
// Related Topics 栈 树 深度优先搜索 二叉树 👍 1169 👎 0
#include <vector>

using namespace std;
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
    void postorderTraversal(TreeNode *root,vector<int> &vec) {
        if (root == nullptr) return;
        postorderTraversal(root->left,vec);
        postorderTraversal(root->right,vec);
        vec.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode *root) {
        if (root == nullptr) return {};
        vector<int> vec;
        postorderTraversal(root,vec);
        return vec;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

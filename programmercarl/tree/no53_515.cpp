//给定一棵二叉树的根节点 root ，请找出该二叉树中每一层的最大值。
//
//
//
// 示例1：
//
//
//
//
//输入: root = [1,3,2,5,3,null,9]
//输出: [1,3,9]
//
//
// 示例2：
//
//
//输入: root = [1,2,3]
//输出: [1,3]
//
//
//
//
// 提示：
//
//
// 二叉树的节点个数的范围是 [0,10⁴]
//
// -2³¹ <= Node.val <= 2³¹ - 1
//
//
//
//
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 363 👎 0

#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
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
    vector<int> largestValues(TreeNode* root) {
        if (root == nullptr) return {};
        queue<TreeNode *> q;
        vector<int> res;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            int largest=INT_MIN;
            for (int i = 0; i < size; ++i) {
                auto item = q.front();
                largest=max(largest,item->val);
                q.pop();
                if (item->left) q.push(item->left);
                if (item->right) q.push(item->right);
            }
            res.push_back(largest);
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

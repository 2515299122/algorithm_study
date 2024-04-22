//给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。
//
// 叶子节点 是指没有子节点的节点。
//
// 示例 1：
//
//
//输入：root = [1,2,3,null,5]
//输出：["1->2->5","1->3"]
//
//
// 示例 2：
//
//
//输入：root = [1]
//输出：["1"]
//
//
//
//
// 提示：
//
//
// 树中节点的数目在范围 [1, 100] 内
// -100 <= Node.val <= 100
//
//
// Related Topics 树 深度优先搜索 字符串 回溯 二叉树 👍 1129 👎 0

#include <string>
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
    void traversal(TreeNode *root, string path, vector<string> &vec) {
        if (root == nullptr) return;
        path += to_string(root->val);
        if(root->left== nullptr&& root->right== nullptr){
            vec.push_back(path);
        }else{
            traversal(root->left,path+"->",vec);
            traversal(root->right,path+"->",vec);
        }
    }

    vector<string> binaryTreePaths(TreeNode *root) {
        if (root == nullptr) return {};
        vector<string> vec;
        traversal(root,"",vec);
        return vec;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

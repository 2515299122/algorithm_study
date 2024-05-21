//
// Created by Administrator on 2024/5/21.
//
//给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
//
//
//
// 示例 1：
//
//
//输入：nums = [1,2,3]
//输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
//
//
// 示例 2：
//
//
//输入：nums = [0,1]
//输出：[[0,1],[1,0]]
//
//
// 示例 3：
//
//
//输入：nums = [1]
//输出：[[1]]
//
//
//
//
// 提示：
//
//
// 1 <= nums.length <= 6
// -10 <= nums[i] <= 10
// nums 中的所有整数 互不相同
//
//
// Related Topics 数组 回溯 👍 2887 👎 0
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    vector<int> used;

    vector<vector<int>> permute(vector<int> &nums) {
        used.resize(nums.size());
        fill(used.begin(), used.end(), false);
        traversal(nums);
        return res;
    }

    void traversal(vector<int> &nums) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) continue;
            path.push_back(nums[i]);
            used[i]= true;
            traversal(nums);
            used[i]= false;
            path.pop_back();
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)

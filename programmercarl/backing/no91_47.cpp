//
// Created by Administrator on 2024/5/22.
//
//给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
//
//
//
// 示例 1：
//
//
//输入：nums = [1,1,2]
//输出：
//[[1,1,2],
// [1,2,1],
// [2,1,1]]
//
//
// 示例 2：
//
//
//输入：nums = [1,2,3]
//输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
//
//
//
//
// 提示：
//
//
// 1 <= nums.length <= 8
// -10 <= nums[i] <= 10
//
//
// Related Topics 数组 回溯 👍 1567 👎 0

#include <vector>
#include <algorithm>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    vector<int> used;

    vector<vector<int>> permuteUnique(vector<int> &nums) {
        sort(nums.begin(), nums.end());
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
            if (i > 0 && nums[i] == nums[i - 1] && used[i-1]) continue;
            if(used[i]== false){
                path.push_back(nums[i]);
                used[i] = true;
                traversal(nums);
                used[i] = false;
                path.pop_back();
            }
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)

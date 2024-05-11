//
// Created by Administrator on 2024/5/11.
//
//给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
//
// candidates 中的每个数字在每个组合中只能使用 一次 。
//
// 注意：解集不能包含重复的组合。
//
//
//
// 示例 1:
//
//
//输入: candidates = [10,1,2,7,6,1,5], target = 8,
//输出:
//[
//[1,1,6],
//[1,2,5],
//[1,7],
//[2,6]
//]
//
// 示例 2:
//
//
//输入: candidates = [2,5,2,1,2], target = 5,
//输出:
//[
//[1,2,2],
//[5]
//]
//
//
//
// 提示:
//
//
// 1 <= candidates.length <= 100
// 1 <= candidates[i] <= 50
// 1 <= target <= 30
//
//
// Related Topics 数组 回溯 👍 1543 👎 0

#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        traversal(candidates, target, 0);
        return res;
    }

    void traversal(vector<int> &candidates, int target, int startIndex) {
        if (target < 0) return;
        if (target == 0) {
            res.push_back(vector<int>(path));
            return;
        }
        for (int i = startIndex; i < candidates.size() && candidates[i] <= target; ++i) {
            //第一个节点可以，后面树层去重
            if (i > startIndex && candidates[i] == candidates[i - 1]) continue;
            path.push_back(candidates[i]);
            target -= candidates[i];
            traversal(candidates, target, i + 1);
            target += candidates[i];
            path.pop_back();
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)

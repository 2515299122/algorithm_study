//给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。
//
//
//
// 示例 1:
//
//
//输入: nums = [1,1,1,2,2,3], k = 2
//输出: [1,2]
//
//
// 示例 2:
//
//
//输入: nums = [1], k = 1
//输出: [1]
//
//
//
// 提示：
//
//
// 1 <= nums.length <= 10⁵
// k 的取值范围是 [1, 数组中不相同的元素的个数]
// 题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的
//
//
//
//
// 进阶：你所设计算法的时间复杂度 必须 优于 O(n log n) ，其中 n 是数组大小。
//
// Related Topics 数组 哈希表 分治 桶排序 计数 快速选择 排序 堆（优先队列） 👍 1812 👎 0

#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    //小根堆
    class MyComparison {
    public:
        bool operator()(const pair<int, int> &p1, const pair<int, int> &p2) {
            return p1.second > p2.second;
        }
    };

    vector<int> topKFrequent(vector<int> &nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int, int>>, MyComparison> pq;
        unordered_map<int, int> map;
        for (const auto &item: nums) {
            map[item]++;
        }
        for (const auto &item: map) {
            pq.push(item);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

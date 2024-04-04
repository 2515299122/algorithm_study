//给你四个整数数组 nums1、nums2、nums3 和 nums4 ，数组长度都是 n ，请你计算有多少个元组 (i, j, k, l) 能满足：
//
//
// 0 <= i, j, k, l < n
// nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
//
//
//
//
// 示例 1：
//
//
//输入：nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
//输出：2
//解释：
//两个元组如下：
//1. (0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) + (-1)
// + 2 = 0
//2. (1, 1, 0, 0) -> nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) + (-1)
// + 0 = 0
//
//
// 示例 2：
//
//
//输入：nums1 = [0], nums2 = [0], nums3 = [0], nums4 = [0]
//输出：1
//
//
//
//
// 提示：
//
//
// n == nums1.length
// n == nums2.length
// n == nums3.length
// n == nums4.length
// 1 <= n <= 200
// -2²⁸ <= nums1[i], nums2[i], nums3[i], nums4[i] <= 2²⁸
//
//
// Related Topics 数组 哈希表 👍 989 👎 0

#include <vector>
#include <unordered_map>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4) {
        vector<int> vec1;
        vector<int> vec2;
        unordered_map<int, int> map;
        int res = 0;

        for (const auto &m: nums1) {
            for (const auto &n: nums2) {
                vec1.push_back(m + n);
                map[m+n]++;
            }
        }
        for (const auto &m: nums3) {
            for (const auto &n: nums4) {
                if(map[-(m+n)]!=0){
                    res+=map[-(m+n)];
                }
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

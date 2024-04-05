//给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[
//b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：
//
//
// 0 <= a, b, c, d < n
// a、b、c 和 d 互不相同
// nums[a] + nums[b] + nums[c] + nums[d] == target
//
//
// 你可以按 任意顺序 返回答案 。
//
//
//
// 示例 1：
//
//
//输入：nums = [1,0,-1,0,-2,2], target = 0
//输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
//
//
// 示例 2：
//
//
//输入：nums = [2,2,2,2,2], target = 8
//输出：[[2,2,2,2]]
//
//
//
//
// 提示：
//
//
// 1 <= nums.length <= 200
// -10⁹ <= nums[i] <= 10⁹
// -10⁹ <= target <= 10⁹
//
//
// Related Topics 数组 双指针 排序 👍 1898 👎 0
#include <vector>
#include <algorithm>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
using LL = long long;

class Solution {
public:
    // 思路：类比《三数之和》，先排序，然后枚举并固定a b，利用首尾指针寻找 c d
    vector<vector<int>> fourSum(vector<int>& nums, int x) {
        if(nums.size()<4)return {};
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-3;++i){
            // 由于nums[i]对应的元素值已经枚举过了，不需要再次枚举了
            if(i>0&&nums[i]==nums[i-1])continue;
            // 以下代码与 三数之和 一样
            for(int j=i+1;j<nums.size()-2;++j){
                // 由于nums[i]对应的元素值已经枚举过了，不需要再次枚举了
                if(j>i+1&&nums[j]==nums[j-1])continue;
                // 首尾指针来寻找c d
                int l=j+1,r=nums.size()-1;
                while(l<r){
                    LL sum=0LL+nums[i]+nums[j]+nums[r]+nums[l];
                    if(sum>x)r--;// sum太大，向左逼近
                    else if(sum<x)l++;// sum太小，向右逼近
                    else{
                        // 添加结果
                        res.push_back({nums[i],nums[j],nums[l],nums[r]});
                        // 缩小区间
                        l++,r--;
                        while(l<r&&nums[l]==nums[l-1])l++;
                        while(l<r&&nums[r]==nums[r+1])r--;
                    }
                }
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

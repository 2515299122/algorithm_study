#include <iostream>
class Solution {
public:
    int mySqrt(int x) {
        long left = 0, mid, ans, right = x, result;
        while (left <= right) {
            mid = left + ((right - left) >> 2);
            result = mid * mid;
            if (result > x) {
                right = mid - 1;
            } else if (result < x) {
                ans = mid;//保留小于的结果，实在找不到就向下取整
                left = mid + 1;
            } else {
                return mid;
            }
        }
        return ans;
    }
};
int main(){
    Solution s;
    std::cout<<s.mySqrt(8192);
}
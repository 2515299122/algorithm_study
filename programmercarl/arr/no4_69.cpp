#include <iostream>
class Solution {
public:
    int mySqrt(int x) {
        //计算x二进制位数
        int count = 0, tmp = x;
        while (tmp) {
            tmp >>= 1;
            count++;
        }
        int left = 0, right = 1<<count, mid, result;
        while (left <= right) {
            mid = left + ((right - left) >> 2);
            result = mid * mid;
            if (result > x){
                right=mid-1;
            } else if(result<x){
                left=mid+1;
            } else{
                return mid;
            }
        }
        return mid;
    }
};
int main(){
    Solution s;
    std::cout<<s.mySqrt(8192);
}
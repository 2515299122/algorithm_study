//给你一个正整数 n ，生成一个包含 1 到 n² 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
//
//
//
// 示例 1：
//
//
//输入：n = 3
//输出：[[1,2,3],[8,9,4],[7,6,5]]
//
//
// 示例 2：
//
//
//输入：n = 1
//输出：[[1]]
//
//
//
//
// 提示：
//
//
// 1 <= n <= 20
//
//
// Related Topics 数组 矩阵 模拟 👍 1271 👎 0

#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> vec(n, vector<int>(n));
        int left = 0, right = n - 1, top = 0, bottom = n - 1;
        int num = 0;
        for (int count = 0; count < n / 2; ++count) {
            for (int i = left; i < right; ++i) {
                vec[top][i] = ++num;
            }
            for (int i = top; i < bottom; i++) {
                vec[i][right] = ++num;
            }
            for (int i = right; i > left; --i) {
                vec[bottom][i] = ++num;
            }
            for (int i = bottom; i > top; i--) {
                vec[i][left] = ++num;
            }
            left++;
            right--;
            top++;
            bottom--;
        }
        if (n % 2 == 1)vec[n / 2][n / 2] = ++num;
        return vec;
    }

};
//leetcode submit region end(Prohibit modification and deletion)

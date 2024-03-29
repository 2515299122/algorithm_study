//给定一个二维数组 array，请返回「螺旋遍历」该数组的结果。
//
// 螺旋遍历：从左上角开始，按照 向右、向下、向左、向上 的顺序 依次 提取元素，然后再进入内部一层重复相同的步骤，直到提取完所有元素。
//
//
//
// 示例 1：
//
//
//输入：array = [[1,2,3],[8,9,4],[7,6,5]]
//输出：[1,2,3,4,5,6,7,8,9]
//
//
// 示例 2：
//
//
//输入：array  = [[1,2,3,4],[12,13,14,5],[11,16,15,6],[10,9,8,7]]
//输出：[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16]
//
//
//
//
// 限制：
//
//
// 0 <= array.length <= 100
// 0 <= array[i].length <= 100
//
//
// 注意：本题与主站 54 题相同：https://leetcode-cn.com/problems/spiral-matrix/
//
//
//
// Related Topics 数组 矩阵 模拟 👍 602 👎 0

#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> spiralArray(vector<vector<int>> &array) {
        if (array.empty()) return {};
        int left = 0, right = array[0].size() - 1, top = 0, bottom = array.size() - 1;
        vector<int> vec;
        while (true) {
            for (int i = left; i <= right; i++) {
                vec.push_back(array[top][i]);
            }
            if (++top > bottom) break;
            for (int i = top; i <= bottom; i++) {
                vec.push_back(array[i][right]);
            }
            if (--right < left)break;
            for (int i = right; i >= left; i--) {
                vec.push_back(array[bottom][i]);
            }
            if (--bottom < top) break;
            for (int i = bottom; i >= top; i--) {
                vec.push_back(array[i][left]);
            }
            if (++left > right)break;
        }
        return vec;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

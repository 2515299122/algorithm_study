//给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。
//
// 如果可以，返回 true ；否则返回 false 。
//
// magazine 中的每个字符只能在 ransomNote 中使用一次。
//
//
//
// 示例 1：
//
//
//输入：ransomNote = "a", magazine = "b"
//输出：false
//
//
// 示例 2：
//
//
//输入：ransomNote = "aa", magazine = "ab"
//输出：false
//
//
// 示例 3：
//
//
//输入：ransomNote = "aa", magazine = "aab"
//输出：true
//
//
//
//
// 提示：
//
//
// 1 <= ransomNote.length, magazine.length <= 10⁵
// ransomNote 和 magazine 由小写英文字母组成
//
//
// Related Topics 哈希表 字符串 计数 👍 873 👎 0

#include <string>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int arr[26]{0};
        for (int i = 0; i < ransomNote.size(); ++i) {
            arr[ransomNote[i] - 'a']++;
        }
        for (int i = 0; i < magazine.size(); ++i) {
            --arr[magazine[i] - 'a'];
        }
        for (int i = 0; i < 26; ++i) {
            if (arr[i] > 0)
                return false;
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

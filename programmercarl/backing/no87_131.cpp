//
// Created by Administrator on 2024/5/13.
//
//给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。
//
//
//
// 示例 1：
//
//
//输入：s = "aab"
//输出：[["a","a","b"],["aa","b"]]
//
//
// 示例 2：
//
//
//输入：s = "a"
//输出：[["a"]]
//
//
//
//
// 提示：
//
//
// 1 <= s.length <= 16
// s 仅由小写英文字母组成
//
//
// Related Topics 字符串 动态规划 回溯 👍 1784 👎 0

#include <vector>
#include   <string>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<string >> res;
    vector<string> path;

    bool isPalindrome(const string &s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }
    void traversal(string s ,int startIndex){
        if(startIndex==s.size()){
            res.push_back(path);
            return;
        }
        for (int i = startIndex; i < s.size(); ++i) {
            if(isPalindrome(s,startIndex,i)){
                path.push_back(s.substr(startIndex,i-startIndex+1));
            } else{
                continue;
            }
            traversal(s,i+1);
            path.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        traversal(s,0);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

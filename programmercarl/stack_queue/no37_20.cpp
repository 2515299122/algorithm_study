//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
//
// 有效字符串需满足：
//
//
// 左括号必须用相同类型的右括号闭合。
// 左括号必须以正确的顺序闭合。
// 每个右括号都有一个对应的相同类型的左括号。
//
//
//
//
// 示例 1：
//
//
//输入：s = "()"
//输出：true
//
//
// 示例 2：
//
//
//输入：s = "()[]{}"
//输出：true
//
//
// 示例 3：
//
//
//输入：s = "(]"
//输出：false
//
//
//
//
// 提示：
//
//
// 1 <= s.length <= 10⁴
// s 仅由括号 '()[]{}' 组成
//
//
// Related Topics 栈 字符串 👍 4422 👎 0

#include <string>
#include <stack>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isValid(string s) {
        if(s.length()%2) return false;
        stack<char> sta;
        for (const auto &item: s){
            if(item=='{') sta.push('}');
            else if(item=='[') sta.push(']');
            else if(item=='(') sta.push(')');
            else if(sta.empty()) return false;
            else if(sta.top()!=item) return false;
            else sta.pop();
        }
        return sta.empty();
    }
};
//leetcode submit region end(Prohibit modification and deletion)

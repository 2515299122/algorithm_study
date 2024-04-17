class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size())return "";
        unordered_map<char, int> m;
        int need = t.size();//窗口还需要的有效字符
        for (int i = 0; i < t.size(); ++i) {
            m[t[i]]++;
        }
        int start = 0, end = -1, minLen = INT_MAX;
        for (int left = 0, right = 0; right < s.size(); right++) {
            //右窗口扩大
            char ch = s[right];       // 窗口中新加入的字符
            //该字符出现再子字符中
            if (m.find(ch) != m.end()) {
                //还有需要的ch，所需need-1
                if (m[ch] > 0) {
                    need--;
                }
                m[ch]--;
            }
            //满足条件，缩小左边界寻找最小边界
            while (need == 0) {
                //满足题意，判断是否是最短字串
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                    end = right;
                }
                ch = s[left];
                //准备删去的字符为出现在字串中
                if (m.find(ch) != m.end()) {
                    //必要字符不可删除，删除后need+1
                    if (m[ch] >= 0) {//若=0刚好，但之后左边界右移则不够数量了
                        need++;
                    }
                    m[ch]++;//虽然增加了但不一定大于0
                }
                left++;
            }
        }
        return s.substr(start, end - start + 1);
    }
};
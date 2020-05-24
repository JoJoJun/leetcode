# 最小覆盖子串
给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字符的最小子串。

>示例：
输入: S = "ADOBECODEBANC", T = "ABC"
输出: "BANC"
说明：
如果 S 中不存这样的子串，则返回空字符串 ""。
如果 S 中存在这样的子串，我们保证它是唯一的答案。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-window-substring
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

# 分析
滑动窗口
```
left = 0, right = 0, valid = 0;
记录答案的元素--> 开始和长度
while right < s.size():
  c = s[right]
  right ++
  添加到右边 
  while 可以向左移：
    d = s[left]
    left ++
    窗口更新
```

# Code
```cpp
class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0, right = 0, valid = 0;
        int len = INT_MAX;
        int start = 0;
        unordered_map<char, int>need, window;
        for(char c : t)
            need[c]++;
        while(right < s.size()){
            char c = s[right];
            right ++;
            if(need.count(c)){
                window[c]++;
                if(window[c]==need[c])
                    valid ++;
            }
            while(valid == need.size()){
                if(right - left < len){
                    len = right - left;
                    start = left;
                }
                char d = s[left];
                left ++;
                if(need.count(d)){
                    if(window[d]==need[d])
                        valid --;
                    window[d]--;
                }
            }

        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};
```

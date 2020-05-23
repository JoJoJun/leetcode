# 无重复字符的最长子串

给定一个字符串，请你找出其中不含有重复字符的 最长子串的长度。

>示例 1:
输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:
输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:
输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
# 分析
滑动窗口
窗口左边为left  右边为i 
不断判断新读入的字符是否已经在窗口中：
  如果在，退出窗口左边的字符，left+1
正常i+1向右滑动 窗口中继续添加 判断当前窗口内条件
# 代码
C++
```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlength = 0;
        int len = s.length();
        if(len<=0)
        return 0;
        if(len == 1)
        return 1;
        unordered_set<char>lookup;
        int left = 0;
        for(int i = 0;i<len;i++){
            while(lookup.find(s[i])!=lookup.end()){
                lookup.erase(s[left]);
                left ++;
            }
            lookup.insert(s[i]);
            if(i-left+1 > maxlength)
             maxlength = i-left+1;
        }
        return maxlength;
    }
};
```

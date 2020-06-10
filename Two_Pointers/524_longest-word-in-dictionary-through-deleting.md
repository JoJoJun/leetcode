# [通过删除字母匹配到字典里最长单词](https://leetcode-cn.com/problems/longest-word-in-dictionary-through-deleting/)

给定一个字符串和一个字符串字典，找到字典里面最长的字符串，该字符串可以通过删除给定字符串的某些字符来得到。如果答案不止一个，返回长度最长且字典顺序最小的字符串。如果答案不存在，则返回空字符串。

> 示例 1:
>
> 输入:
> s = "abpcplea", d = ["ale","apple","monkey","plea"]
>
> 输出: 
> "apple"
> 示例 2:
>
> 输入:
> s = "abpcplea", d = ["a","b","c"]
>
> 输出: 
> "a"
> 说明:

所有输入的字符串只包含小写字母。
字典的大小不会超过 1000。
所有输入的字符串长度不会超过 1000。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-word-in-dictionary-through-deleting
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

# 分析

其实就是依次判断字符串里是否包含这些字串，选择最长的且字典序最小的。可以对字典排序后来找，也可以直接找判断字段序是不是小。

就是判断字符串是否包含这些子串时需要用到双指针。两个指针分贝指向s和candidate的开始，如果匹配上，两个指针都前移；否则s指针前移。知道到达末尾或者全部匹配上

# 代码

C++

排序的话就O(nlogn+n*x)

不排序的话就是O(n*x)

```cpp
class Solution {
public:
    bool iscontained(string s1, string s2){
        int l1 = s1.length(),l2 = s2.length();
        int i = 0, j = 0;
        int samenum = 0;
        while(i<l1 && j<l2){
            if(s1[i]==s2[j]){
                samenum++;
                i++;
                j++;
                if(samenum == l2)
                return true;
            }
            else i++;
        }
        return false;
    }
    string findLongestWord(string s, vector<string>& d) {
        //sort(d.begin(),d.end());
        int len = s.length();
        string ans ="";
        for(int i = 0;i<d.size();i++){
            string temp = d[i];
            if(iscontained(s,temp) ){
                if(temp.length() > ans.length() || (temp.length() == ans.length() && temp<ans))
                ans = temp;
            }
        }
        return ans;
    }
};
```



Python

```python
class Solution:
    def iscontained(self,s,str1):
        i = 0
        j = 0
        len1 = len(s)
        len2 = len(str1)
        samen = 0
        while i<len1 and j<len2:
            if s[i]==str1[j]:
                i+=1
                j+=1
                samen += 1
                if samen == len2:
                    return True
            else:
                i+=1
        return False
    def findLongestWord(self, s: str, d: List[str]) -> str:
        ans = ""
        for str1 in d:
            if self.iscontained(s,str1):
                if (len(ans)<len(str1)) or(len(ans)==len(str1) and str1<ans):
                    ans = str1
        return ans
```


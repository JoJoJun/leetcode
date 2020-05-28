# 验证回文字符 II

给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。

> 示例 1:
>
> 输入: "aba"
> 输出: True
> 示例 2:
>
> 输入: "abca"
> 输出: True
> 解释: 你可以删除c字符。
> 注意:

字符串只包含从 a-z 的小写字母。字符串的最大长度是50000。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-palindrome-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

# 分析

回文串就很适合用左右双指针

只不过这里带了一小丢丢的回溯思想（当然也不用回溯）

就是要判断跳过一个字符之后还时不时回文的

# 代码

python 

```python
class Solution:
    def validPalindrome(self, s: str) -> bool:
        length = len(s)
        i = 0
        j = length-1
        while i<j:
            if(s[i]!=s[j]):
                return self.isvalid(s,i+1,j) or self.isvalid(s,i,j-1)
            i+=1
            j-=1
        return True
        
    def isvalid(self,s,i,j):
       
        while i<=j:
            if s[i] != s[j]:
                self.ii = i
                self.jj = j
                return False
            i+=1
            j-=1
        return True
```


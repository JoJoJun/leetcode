# 描述
累加数
累加数是一个字符串，组成它的数字可以形成累加序列。

一个有效的累加序列必须至少包含 3 个数。除了最开始的两个数以外，字符串中的其他数都等于它之前两个数相加的和。

给定一个只包含数字 '0'-'9' 的字符串，编写一个算法来判断给定输入是否是累加数。

说明: 累加序列里的数不会以 0 开头，所以不会出现 1, 2, 03 或者 1, 02, 3 的情况。

示例 1:

输入: "112358"
输出: true 
解释: 累加序列为: 1, 1, 2, 3, 5, 8 。1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
示例 2:

输入: "199100199"
输出: true 
解释: 累加序列为: 1, 99, 100, 199。1 + 99 = 100, 99 + 100 = 199
进阶:
你如何处理一个溢出的过大的整数输入?

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/additive-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
# 分析
这题和以前对字符串中数字选择的是一样的，利用子串
只是有大数的问题，但是用python就很好处理
```
backtrack:
  判断条件--> 三个数，遍历完了，一直是true； 不满足斐波那契条件，为false
  列出所有选项 -->  0到现在的子串 （因为字符串是递减的）
  是否合法 --> 不能以0开头
  更新状态 --> 已分析的字符串 和剩余字符串
  step forward
  恢复状态
```

# Code
Python
```python
class Solution:
    def isAdditiveNumber(self, num: str) -> bool:
        temp = []
        return self.backtrack(num,temp)
    
    def backtrack(self,num,temp):
        n = len(temp)
        
        if len(temp) >=3 and temp[n-1] != temp[n-2]+temp[n-3]:
            return False
        if len(num)==0 and n>=3:
            return True
        for i in range(len(num)):
            cur = num[0:i+1]
            if cur[0]=='0' and len(cur)!=1:
                continue
            temp.append(int(cur))
            if self.backtrack(num[i+1:],temp):
                return True
            temp.pop()
        return False
```

# 描述
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
示例:

输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
说明:
尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
# 分析
用决策树去理解，相当于第一层是"2"对应的"abc"中的任意一个，向下走每一分支是"3"对应的"def"中的任意一个字母，很明显可以用回溯的思想
```
backtrack:
  判断条件 -->所有数字都取了一个字母，则加入答案中
  列出当前所有选项 --> 给定字符串当前数字对应的所有的字母
  判断是否合法
  更新状态
  step forward --> 经过的数字数
  恢复状态
```
这里用python处理字符串的[:-1]很好用，就直接用了python
注意空的时候返回[]而不是[""]
# 代码
```python
class Solution:
     
    def letterCombinations(self, digits: str) -> List[str]:
        if digits == "":
            return []
        candidates=["","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"]
        ans = []
        temp = ""
        self.backtrack(0,temp,digits,ans,candidates)
        return ans
    def backtrack(self,step,temp,digits,ans,candidates):
        if(step == len(digits) and temp !=""):
            ans.append(temp)
        
        if(step < len(digits)):
            current = candidates[int(digits[step])]
            for c in current:
                temp += c
                self.backtrack(step+1,temp,digits,ans,candidates)
                temp = temp[:-1]
    
   
```

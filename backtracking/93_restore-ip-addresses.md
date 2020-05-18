# decs
给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。

有效的 IP 地址正好由四个整数（每个整数位于 0 到 255 之间组成），整数之间用 '.' 分隔。


>示例:
输入: "25525511135"
输出: ["255.255.11.135", "255.255.111.35"]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/restore-ip-addresses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
# analysis
backtrack:
  判断条件-->字符串到结尾且正好有四段
  列出选项 -->从上次划分结束的位置开始划分
  判断选项 --> 0-255之间，且不是0开头的非0数字
  更新状态
  step forward
  恢复状态

非常适合用python int()直接字符串转主子，'.'join直接数字变字符串
# code
python：
```python
class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        self.ans = []
        temp = []
        self.backtrack(temp, s, 0)
        return self.ans
    
    def backtrack(self, temp, s, start):
        if len(temp) == 4 and start == len(s):
            self.ans.append('.'.join(temp))
        elif len(temp)==4:
            return
        for i in range(1, len(s) - start+1): # 这里踩坑 要有+1 因为后面是开区间
            stemp = s[start:start + i]
            if stemp != "0" and stemp[0]=='0':
                continue
            if len(temp)==3:
                stemp = s[start:]  # 加上这组条件 时间会快很多
            inttemp = int(stemp)
            if inttemp >= 0 and inttemp <= 255:
                temp.append(stemp)
                self.backtrack(temp, s, start + i)
                temp.pop(len(temp)-1)
            else:
                break
```

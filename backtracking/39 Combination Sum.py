'''
描述
给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
candidates 中的数字可以无限制重复被选取。
说明：
所有数字（包括 target）都是正整数。
解集不能包含重复的组合。 
示例 1:
输入: candidates = [2,3,6,7], target = 7,
所求解集为:
[
  [7],
  [2,2,3]
]
示例 2:

输入: candidates = [2,3,5], target = 8,
所求解集为:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]

 '''
不可重复取，可以按照从哪里开始来进行下一层

class Solution:
    def backtrack(self,ans, cur, candidates, target,l):
        if target == 0:
            ans.append(list(cur))
            return
        if target < candidates[0]:
            return
        r = len(candidates)
        for i in range(l, r):
            num = candidates[i]
            target -= num
            cur.append(num)
            self.backtrack(ans, cur, candidates, target, i)
            cur.remove(num)
            target += num
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        ans = []
        cur = []
        candidates = sorted(candidates)
        self.backtrack(ans, cur, candidates, target, 0)
        return ans
        


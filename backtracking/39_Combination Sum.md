
# 描述
给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
candidates 中的数字可以无限制重复被选取。
说明：
所有数字（包括 target）都是正整数。
解集不能包含重复的组合。 
>示例 1:
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

# 分析
每个数可以取多次，但是[2,3]之后就没必要考虑[3,2]了，所以不同于排列，更像是求子集，每次从当前位置开始，而不是0开始。
backtrack:
  判断条件or直接操作 --> 判断和
  列出选项 --> 从当前数开始往后
  条件是否符合
  更新状态
  step forward
  恢复状态
 # Code
```cpp
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        vector<vector<int>>ans;
        backtrack(0,candidates,temp,ans,target);
        return ans;
    }
    void backtrack(int k, vector<int>& candidates, vector<int>& temp,vector<vector<int>>& ans,int target){
        if(target==0){
            ans.push_back(temp);
        }
        else if(target<0){
            return ;
        }
        for(int i = k;i<candidates.size();i++){
            temp.push_back(candidates[i]);
            target -= candidates[i];
            backtrack(i,candidates,temp,ans,target);
            temp.pop_back();
            target += candidates[i];
        }
    }
};
```
```python
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
  ```
        


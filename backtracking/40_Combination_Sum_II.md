# 题目
给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用一次。

说明：

所有数字（包括目标数）都是正整数。
解集不能包含重复的组合。 
>示例1:
输入: candidates = [10,1,2,7,6,1,5], target = 8,
所求解集为:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
示例 2:
输入: candidates = [2,5,2,1,2], target = 5,
所求解集为:
[
  [1,2,2],
  [5]
]


# 描述
与39的区别在于备选数字里有重复的数字，答案中要去重，即取第一个1和取第二个1是同一种答案  
可以简单一点直接用set来解决问题，也可以跳过相同项，因为[1,1,1,2,3]能组合出来的sum必然是包含了[1,1,2,3]，就没必要来三个[1,2,3]了（因为有三个1） 
思路仍然是：

判断是否满足了递归出口（比如符合寻找条件或者越界）；
在当前可选的选项里（比如方向、备选数等）：
   判断当前选项是否满足条件 ，满足的话更新当前状态,递归，在恢复之前状态
# Code
代码如下：
```cpp
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>temp;
        vector<vector<int>>ans;
        sort(candidates.begin(),candidates.end());
        backtrack(0,temp,candidates,ans,target);
        return ans;
    }
    void backtrack(int k, vector<int>&temp, vector<int>&candidates,vector<vector<int>>&ans,int target)    {
        if(target == 0){
            ans.push_back(temp);
        }
        else if(target<0)
        return;
        for(int i = k; i<candidates.size();i++){
            if( i!=k && candidates[i]==candidates[i-1] )continue;
            target -= candidates[i];
            temp.push_back(candidates[i]);
            backtrack(i+1,temp,candidates,ans,target);
            target += candidates[i];
            temp.pop_back();
        }
    }
};
```

# 描述
给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
说明：解集不能包含重复的子集。
示例:
>输入: [1,2,2]
输出:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

# 分析
```
backtrack:
  add or decide
  list all options at present
    if option is valid:
      update states
      step forward
      pop update
```   
与78想比，主要是数组中有重复元素
对于[2,1,2，3]排序后[1,2,2,3] [2,3]和[2,3]是一样的，但是[2,2,3]又是必须的
其实是在遍历选项时，如果当前索引不是此轮的开始索引(k)，值又和前一个值相等，那就是完全重复的
     []
[1]  [2]  [2]  [3] 这里的第2个[2]，向下展开时得到的可能的结果除了[2,2,3]之外是完全一样的，在这一层(k=1)中，完全可以跳过
条件就是 if(i!=start && nums[i]==nums[i-1]) continue
# C++代码
```cpp
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int> > ans;
        sort(nums.begin(),nums.end());
        backtrack(0,nums,temp,ans);
        return ans;
    }
    void backtrack(int k, vector<int>&nums, vector<int>&temp,vector<vector<int>>&ans){
        ans.push_back(temp);
        for(int i = k;i<nums.size();i++){
            if(i!=k && nums[i]==nums[i-1])continue;
            temp.push_back(nums[i]);
            backtrack(i+1,nums,temp,ans);
            temp.pop_back();
        }
    }
};
```

# 描述
在46的基础上，包含了重复的数字，要求答案去重 
> 输入: [1,1,2]
输出:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]

# 分析
仍然是可以用set或者跳过重复数字；  

基本思路不变：
backtrack:
   判断是否满足递归出口 -->已经是n个数；
   列举可选空间  --->数组里n个数；
      符合条件  ---> 没使用过 不重复
      更新当前状态  
      向下递归
      回复当前状态
非set版：
只是在判断条件时加了一条，如果当前数和前一个数相同，且前面那个数没访问过，则跳过（因为访问过了的话其实这代表着两个数，而若没访问过，则是相同地位的）：if(i!=0 && nums[i]==nums[i-1] && !visit[i-1])continue;

>这里必须用visit 而不能像组合或子集一样用 if(i!=k && nums[i] == nums[i-1])continue，是因为没法通过k来判断是不是决策树的同一层，而且每次都是从0开始要包含所有可能的数字，为了避免重复必须用visit数组
# 代码
## 跳过重复
```cpp
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int>>ans;
        vector<bool>visit;
        sort(nums.begin(),nums.end());
        for(int i = 0;i<nums.size();i++)
            visit.push_back(false);
        backtrack(visit,nums,temp,ans);
        return ans;
    }
    void backtrack(vector<bool>&visit,vector<int>&nums,vector<int>&temp,vector<vector<int>>&ans){
        if(temp.size()==nums.size())
        ans.push_back(temp);
        for(int i = 0;i<nums.size();i++){
            if(i!=0 && nums[i]==nums[i-1] && !visit[i-1])continue;
            if(!visit[i]){
                visit[i]=true;
                temp.push_back(nums[i]);
                backtrack(visit,nums,temp,ans);
                temp.pop_back();
                visit[i]=false;
            }
        }
    }
};
```
## set去重
只是在满足条件时不直接加到返回答案里，而是先添加到set<vector<int> > ans里，最后从set里取出来加到vector里返回就好了，具体怎么用注意一下
```cpp
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int>>ans;
        vector<bool>visit;
        sort(nums.begin(),nums.end());
        for(int i = 0;i<nums.size();i++)
            visit.push_back(false);
        set<vector<int>>ansset;
        backtrack(visit,nums,temp,ansset);
	//这里
        set<vector<int>>::iterator it;
        for(it=ansset.begin ();it!=ansset.end ();it++)
        {
            vector<int>t = *it; //这里
            ans.push_back(t);
        }
        return ans;
    }
    void backtrack(vector<bool>&visit,vector<int>&nums,vector<int>&temp,set<vector<int>>&ans){
        if(temp.size()==nums.size())
        	ans.insert(temp);
        for(int i = 0;i<nums.size();i++){
            if(!visit[i]){
                visit[i]=true;
                temp.push_back(nums[i]);
                backtrack(visit,nums,temp,ans);
                temp.pop_back();
                visit[i]=false;
            }
        }
    }
};
```


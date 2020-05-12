
/*
从空集开始，每次加一个树。这个过程中产生的所有temp都是满足要求的；
为了不重复，每次前进的选项里是从k开始，向下走是i+1
*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > ans;
        vector<int>temp;
        backtrack(nums,ans,temp,0);
        return ans;
    }
    void backtrack(vector<int>& nums, vector<vector<int>>&ans,vector<int>temp,int k){
        ans.push_back(temp);
        for(int i = k;i<nums.size();i++){
            temp.push_back(nums[i]);
            backtrack(nums,ans,temp,i+1);
            temp.pop_back();
        }
    }
};

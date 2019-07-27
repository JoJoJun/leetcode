在46的基础上，包含了重复的数字，要求答案去重  
仍然是可以用set或者跳过重复数字；  

基本思路不变：
backtrack:
   判断是否满足递归出口 -->已经是n个数；
   列举可选空间  --->数组里n个数；
      符合条件  ---> 没使用过
      更新当前状态  
      向下递归
      回复当前状态
非set版：
只是在判断条件时加了一条，如果当前数和前一个数相同，且前面那个数没访问过，则跳过（因为访问过了的话其实这代表着两个数，而若没访问过，则是相同地位的）：
class Solution {
public:
    vector<vector<int> >res;
void backtarck(vector<int>cur, vector<int>nums,  vector<bool>visited )
{
	int si = nums.size();
	if (cur.size() == si) {
		res.push_back(cur);
		return;
	}
	for (int i = 0; i < si; i++)
	{
		int n = nums[i];
		if (visited[i] == false) {
			if (i != 0 && nums[i] == nums[i-1] && visited[i-1]== false)
				continue;
			cur.push_back(n);
			visited[i] = true;
			backtarck(cur, nums, visited);
			cur.pop_back();
			visited[i] = false;
		}
	}
}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
	int si = nums.size();
	vector<int>cur;
	vector<bool>visited;
	for (int i = 0; i < si; i++)
		visited.push_back(false);

	backtarck(cur, nums, visited);
	/*for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[i].size(); j++)
		{
			printf("%d ", res[i][j]);
		}
		printf("\n");
	}*/
	return res;
    }
};

set版：
只是在满足条件时不直接加到返回答案里，而是先添加到set<vector<int> > ans里，最后从set里取出来加到vector里返回就好了


全排列：
给定一个没有重复数字的序列，返回其所有可能的全排列。

仍然是可选空间为给定数组，每个数只能用一次，仍然可以用既定的思路：
backtrack:
   判断是否满足递归出口 -->已经是n个数；
   列举可选空间  --->数组里n个数；
      符合条件  ---> 没使用过
      更新当前状态  
      向下递归
      回复当前状态

这里不同于之前组合问题的是，在组合问题中，只要将数组排序，每次都向右寻找就可以，因为要的是和，前面的已经求过了；但是在全排列中在当次递归中是可以用到左边的数据的，
因为并不是按顺序来的，对于[1,2,3]，第一次递归时可以从1开始，也可以回退之后从2开始，然后去前面找，所以要用额外的visited数组来表明数据是否已经被使用过  
代码如下：  
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
		if (visited[i] == false)
		{
			visited[i] = true;
			cur.push_back(n);
			backtarck(cur, nums, visited);
			cur.pop_back();
			visited[i] = false;
		}
	}
}
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
	int si = nums.size();
	vector<int>cur;
	vector<bool>visited;
	for (int i = 0; i < si; i++)
		visited.push_back(false);

	backtarck(cur, nums, visited);
        return res;
    }
};

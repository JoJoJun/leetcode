描述：
找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。
说明：
所有数字都是正整数。
解集不能包含重复的组合。 
示例 1:
输入: k = 3, n = 7
输出: [[1,2,4]]
示例 2:
输入: k = 3, n = 9
输出: [[1,2,6], [1,3,5], [2,3,4]]


//也就是相较 39 和 40 多了的条件是组合的长度必须为k个数，所以递归的时候如果超出了k个数就可以直接回退了
仍然满足前两道的递归思路：
backtrack:
   是否满足递归出口；
   在可选的条件下：
      当前可选，则更新当前状态，向下递归；回复之前状态

避免重复也是体现在排序后，可选条件每次后移一个，保证向下递归时不会用到重复的数字
class Solution {
public:
	vector<vector<int>>ans;
	void backtrack(vector<int>cur, int k, int n, int left)
	{
		if (cur.size() > k)
			return;
		int sum = 0;
		for (int i = 0; i < cur.size(); i++)
		{
			sum += cur[i];
		}
		if (sum > n)
			return;
		if (cur.size() == k)
		{
			if(sum == n)
			ans.push_back(cur);

			return;
		}
		for (int i = left; i <= 9; i++)
		{
			cur.push_back(i);
			backtrack(cur, k, n, i + 1);
			cur.pop_back();
		}
	}
	vector<vector<int>> combinationSum3(int k, int n) {
		if (n <= 0 || n > 45)
			return ans;
		vector<int>cur;
		backtrack(cur, k, n, 1);
		return ans;
	}
};

递归+ 剪枝
The set [1,2,3,...,n] contains a total of n! unique permutations.
By listing and labeling all of the permutations in order, we get the following sequence for n = 3:
"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.
Note:
Given n will be between 1 and 9 inclusive.
Given k will be between 1 and n! inclusive.

与46 47 类似，看似是找到所有排列里第k个就行，但这样会超时  

还是递归，但边递归边剪枝 
backtrack:
   判断是否满足递归出口 -->递归深度已经达到n；
   列举可选空间  --->数组里n个数；
      符合条件  ---> 没使用过
      剪枝部分  ---> 当前分支分到底最多有 (n-层数-1)!个答案，如果比k小，那么此分即使递归到底也是不符合的，可以直接跳过，k相应变小
      更新当前状态  
      向下递归
              ---->  因为剪掉了要回归的部分，所以不需要恢复之前状态了

class Solution {
public:
	vector<vector<int>>nums; 
	vector<int>jiecheng;
	void calcnums()
	{
		jiecheng.push_back(1);
		jiecheng.push_back(1);
		jiecheng.push_back(2);
		for (int i = 3; i <= 9; i++)
		{
			int top = jiecheng[i - 1];
			jiecheng.push_back(top * i);
		}
		//for (int i = 0; i < jiecheng.size(); i++)
			//printf("%d ", jiecheng[i]);
	}
	void backtrack(vector<int>cur, int n, int k,int depth, vector<bool>visited) {
		if (depth == n)
		{
			nums.push_back(cur);
			return;
		}
		int num_branch = jiecheng[n - depth - 1];
		for (int i = 1; i <= n; i++)
		{ 
			if (visited[i])
				continue;
			if (num_branch < k)
			{
				k -= num_branch;
				continue;
			}
			
			visited[i] = true;
			cur.push_back(i);
			backtrack(cur, n, k, depth + 1, visited);
		}
	}
	string getPermutation(int n, int k) {
		calcnums();
		vector<bool>visited;
		vector<int>cur;
		for (int i = 1; i <= n+1; i++)
			visited.push_back(false);
		backtrack(cur, n, k, 0, visited);

		string ans = "";
		vector<int>last = nums[0];
		for (int i = 0; i < last.size(); i++)
			ans += (last[i] + '0');
		return ans;
	}
};

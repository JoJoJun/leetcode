与39的区别在于备选数字里有重复的数字，答案中要去重，即取第一个1和取第二个1是同一种答案  
可以简单一点直接用set来解决问题，也可以跳过相同项，因为[1,1,1,2,3]能组合出来的sum必然是包含了[1,1,2,3]，就没必要来三个[1,2,3]了（因为有三个1） 
思路仍然是：

判断是否满足了递归出口（比如符合寻找条件或者越界）；
在当前可选的选项里（比如方向、备选数等）：
   判断当前选项是否满足条件 ，满足的话更新当前状态,递归，在恢复之前状态
   
代码如下：
class Solution {
public:
    vector<vector<int> >res;
    void backtrack(vector<int>cur, int target, int sum, vector<int>candidates, int l, int r)
{
	if (sum == target) {
		res.push_back(cur);
		return;
	}
	for (int i = l; i < r; i++)
	{
		int num = candidates[i];
		if (i != l && candidates[i] == candidates[i - 1])
			continue;
		if (sum + num <= target )
		{
			sum += num;
			cur.push_back(num);
			backtrack(cur, target, sum, candidates, i+1, r);
			cur.pop_back();
			sum -= num;
		}
	}
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
	if (target < 0 || target < candidates[0])
		return res;
	vector<int>cur;
	cur.clear();
	backtrack(cur, target, 0, candidates, 0, candidates.size());
        return res;
    }
};

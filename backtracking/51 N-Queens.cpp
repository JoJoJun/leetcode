/*
backtrack:
   判断是否满足递归出口 -->已经放置了n行的皇后；
   列举可选空间  --->一行n个位置；
      符合条件  ---> 放入当前列满足place()
      更新当前状态  
      向下递归
      回复当前状态  -->不需要，因为满足条件才向下递归，否则就覆盖值了

*/

class Solution {
public:
vector<int>x;//棋盘x[i]第i行的x[i]位置有皇后
vector<vector<int>>tempans;//最后再处理成输出要求的字符串
int sum;
int N;
//判断当前位置是否合适
bool place(int k)
{
	for (int i = 0; i < k; i++)
	{
		if (x[i] == x[k] || abs(k - i) == abs(x[k] - x[i]))
			return false;
	}
	return true;
}
//backtrack部分
void quene(int num)
{
	if (num >= N)//出口，放置皇后足够
	{
		sum += 1; //解数+1
		vector<int>temp;
		for (int i = 0; i < N; i++)
		{
			temp.push_back(x[i]);
		}
		tempans.push_back(temp);
	}
	else {
		for (int i = 0; i < N; i++) //一行中可选的位置
		{
			x[num] = i;
			if (place(num))
				quene(num + 1);
		}
	}
}
//入口
 vector<vector<string>> solveNQueens(int n) {
  sum = 0;
	N = n;
	vector<vector<string>> res;
	for (int i = 0; i < n; i++)
		x.push_back(-1);
	quene(0);
	for (int i = 0; i < tempans.size(); i++)
	{
		vector<string>temp;
		for (int j = 0; j < tempans[i].size(); j++)
		{
			string nowans = "";
			for (int k = 0; k < n; k++)
				nowans += '.';
			nowans[tempans[i][j]] = 'Q';
			temp.push_back(nowans);
		}
		res.push_back(temp);
	}
	return res;
    }
};

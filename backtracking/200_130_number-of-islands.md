# 200
## description
岛屿数量
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

岛屿总是被水包围，并且每座岛屿只能由水平方向或竖直方向上相邻的陆地连接形成。

此外，你可以假设该网格的四条边均被水包围。
>示例 1:
输入:
11110
11010
11000
00000
输出: 1
示例 2:
输入:
11000
11000
00100
00011
输出: 3
解释: 每座岛屿只能由水平和/或竖直方向上相邻的陆地连接而成。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-islands
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
## analysis
很明显符合dfs的特征，dfs也属于backtrack大类
遍历整个网格，遇到‘1’就数量加1，然后通过dfs把'1'能到达的‘1’全都标记位0，这样既不需要visited数组来表示是否访问过，也不需要恢复01状态
大致上也符合backtrack思路：
backtrack:
  判断条件 --> 暂时不需要  判断条件在调用者
  列出选项 --> 所有能到的四个位置
  判断选项合法 --> 不超过边界 且是 ‘1’
  更新状态 -->其实是当前坐标
  stepforward
  恢复状态 --> 在传值处修改 回到这层时自然恢复
## code
c++
```cpp
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int num = 0;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[i].size();j++){
                if(grid[i][j]=='1'){
                    num ++;
                    backtrack(i,j,grid);
                }
            }
        }
        return num;
    }
    void backtrack(int i,int j,vector<vector<char>>& grid){
        grid[i][j]='0';
        if(i-1>=0 && grid[i-1][j]=='1')backtrack(i-1,j,grid);
        if(i+1<grid.size() && grid[i+1][j]=='1')backtrack(i+1,j,grid);
        if(j-1>=0 && grid[i][j-1]=='1')backtrack(i,j-1,grid);
        if(j+1<grid[0].size() && grid[i][j+1]=='1')backtrack(i,j+1,grid);
    }
};
java
```java
class Solution {
    public int numIslands(char[][] grid) {
        int num = 0;
        int m = grid.length;
        if(m<=0)
        return num;
        int n = grid[0].length;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]=='1'){
                    num ++ ;
                    backtrack(i,j,m,n,grid);
                }
            }
        }
        return num;
    }
    public void backtrack(int i,int j, int m, int n, char[][] grid){
        grid[i][j]='0';
        int []in={0,0,1,-1};
        int []jn ={1,-1,0,0};
        for(int k = 0;k<4;k++){
            int nowi = i + in[k];
            int nowj = j+jn[k];
            if(nowi>=0 && nowi<m && nowj>=0 && nowj<n && grid[nowi][nowj]=='1')
             backtrack(nowi,nowj,m,n,grid);
        } 
    }
}
```
```
# 130
130和200非常像

## desc
被围绕的区域
给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。

找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。

>示例:
X X X X
X O O X
X X O X
X O X X
运行你的函数后，矩阵变为：
X X X X
X X X X
X X X X
X O X X

解释:

被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/surrounded-regions
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
## analysis
和上面的200非常像
可以这样：
先把四个边缘位置及其相连的‘O'全都找出来标成'P'，因为这些不可能被X包围了；
然后就遍历，把剩下的’O‘标成X，而所有的P恢复O
## code
```java
class Solution {
    int m,n;
    public void solve(char[][] board) {
         m =board.length;
        if(m<=0)
        return ;
         n = board[0].length;
        for(int j=0;j<n;j++){
            if(board[0][j]=='O')
                dfs(0,j,board);
            if(board[m-1][j]=='O')
                dfs(m-1,j,board);
        }
        for(int i = 0;i<m;i++){
            if(board[i][0]=='O')
                dfs(i,0,board);
            if(board[i][n-1]=='O')
                dfs(i,n-1,board);
        }
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(board[i][j]=='O')
                    board[i][j]='X';
                else if (board[i][j]=='P')
                 board[i][j]='O';
            }
        }
    }
    void dfs(int i, int j, char[][]board){
        board[i][j]='P';
        if(i-1>=0 && board[i-1][j]=='O')dfs(i-1,j,board);
        if(i+1<m && board[i+1][j]=='O')dfs(i+1,j,board);
        if(j-1>=0 && board[i][j-1]=='O')dfs(i,j-1,board);
        if(j+1<n && board[i][j+1]=='O')dfs(i,j+1,board);
    }
}
```

# des
给定一个二维网格和一个单词，找出该单词是否存在于网格中。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

 

示例:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

给定 word = "ABCCED", 返回 true
给定 word = "SEE", 返回 true
给定 word = "ABCB", 返回 false
 

>提示：
board 和 word 中只包含大写和小写英文字母。
1 <= board.length <= 200
1 <= board[i].length <= 200
1 <= word.length <= 10^3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-search
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
# analysis
backtrack:
   判断条件 --> word == temp ，如果当前字母不一样就直接return
   list options-->四个方向的字母
   if option is ok -->不能出边界 没访问过
   update states
   step forward
   recover states
  这里卡了比较久的是判断true false，一旦true了之后不需要再慢慢恢复状态了，直接return true
  
# code
```python
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        visited = []
        for i in range(len(board)):
            temp = []
            for j in range(len(board[i])):
                temp.append(False)
            visited.append(temp)
        for i in range(len(board)):
            for j in range(len(board[i])):
                visited[i][j]=True
                if self.backtrack(1,i,j,board[i][j],visited,board,word) :
                    return True
                visited[i][j]=False
        return False
    def backtrack(self,k,r,c,temp,visited,board,word):
        if board[r][c] != word[k - 1]:
            return False
        if word == temp:
            return True
        if k > len(word):
            return False
        rn = [0,0,1,-1]
        cn = [1,-1,0,0]
        for i in range(4):
            nowr = r + rn[i]
            nowc = c+ cn[i]
            if nowr>=0 and nowr<len(board) and nowc>=0 and nowc<len(board[nowr]) and visited[nowr][nowc] == False :
                temp += board[nowr][nowc]
                visited[nowr][nowc] = True
                ans = self.backtrack(k+1,nowr,nowc,temp,visited,board,word)
                if ans :return True
                temp = temp[:-1]
                visited[nowr][nowc] = False
```
```java
class Solution {
    private int m;
    private int n;
    private boolean [][]visited;
    public boolean exist(char[][] board, String word) {
        m = board.length;
         if (m == 0) {
            return false;
        }

        n = board[0].length;
        visited = new boolean[m][n];
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(backtrack(0,i,j,word,board))
                   return true;
            }
        }
        return false;
    }
    public boolean backtrack(int k, int r, int c,String word,char [][]board){
        if(k == word.length()-1)
            return word.charAt(k)==board[r][c];
        if(board[r][c]==word.charAt(k)){
            visited[r][c]=true;
            int [] rn = {0,0,1,-1};
            int [] cn = {1,-1,0,0};
            for(int i = 0;i<4;i++){
                int nowr = r+rn[i];
                int nowc = c + cn[i];
                if(nowr>=0 && nowr<m && nowc>=0 && nowc<n && !visited[nowr][nowc]){
                    if(backtrack(k+1,nowr,nowc,word,board))
                     return true;
                }
            }
            visited[r][c]=false;
        }
        return false;
    }
}
```

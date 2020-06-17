# 搜索二维矩阵

编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：

每行中的整数从左到右按升序排列。
每行的第一个整数大于前一行的最后一个整数。
示例 1:

输入:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
输出: true
示例 2:

输入:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/search-a-2d-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

# 分析

这个题剑指offer里也有，关键用作比较的不是mid，二十右上角那个值。因为这个值明确的，左边都比它小，下边都比它大，每次移动相应的表示行列的值。

```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m==0)return false;
        int n = matrix[0].size();
        int i = 0, j = n-1;
        while(i<m && j>=0){
            int num = matrix[i][j];
            if(num == target)
                return true;
            else if(num < target)
                i+=1;
            else
                j-=1;
        }
        return false;
    }
};
```


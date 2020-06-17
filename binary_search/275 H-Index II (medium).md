# H指数 II

给定一位研究者论文被引用次数的数组（被引用次数是非负整数），数组已经按照升序排列。编写一个方法，计算出研究者的 h 指数。

h 指数的定义: “h 代表“高引用次数”（high citations），一名科研人员的 h 指数是指他（她）的 （N 篇论文中）总共有 h 篇论文分别被引用了至少 h 次。（其余的 N - h 篇论文每篇被引用次数不多于 h 次。）"

 

示例:

输入: citations = [0,1,3,5,6]
输出: 3 
解释: 给定数组表示研究者总共有 5 篇论文，每篇论文相应的被引用了 0, 1, 3, 5, 6 次。
     由于研究者有 3 篇论文每篇至少被引用了 3 次，其余两篇论文每篇被引用不多于 3 次，所以她的 h 指数是 3。


说明:

如果 h 有多有种可能的值 ，h 指数是其中最大的那个。

 

进阶：

这是 H指数 的延伸题目，本题中的 citations 数组是保证有序的。
你可以优化你的算法到对数时间复杂度吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/h-index-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

# 分析

这题难就难在理解题意上。其实是找一个数nums[i]，使得 h = nums[i]>=n-i  。引用次数高于nums[i]的文章有n-i-1篇，再加上这个第i篇，一共n-i。所以至少有h篇满足被引用h以上。

线性查找：

```c++
class Solution {
public:
    int hIndex(vector<int>& citations) {
       
        int n = citations.size();
        if(n==0)return 0;
        for(int i = 0;i<citations.size();i++)
        {
            if(citations[i]>=n-i)
                return n-i;
        }
        return 0;
    }
};
```

二分查找：注意返回值

```python
class Solution:
    def hIndex(self, citations: List[int]) -> int:
        n = len(citations)
        l,r = 0,n-1
        while l<=r:
            mid = l + (r-l)//2
            if citations[mid] == n-mid:
                return n-mid
            elif citations[mid]<n-mid:
                l=mid+1
            else:
                r = mid-1
        return n-l
```


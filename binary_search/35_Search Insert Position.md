# 搜索插入位置

给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

你可以假设数组中无重复元素。

示例 1:

输入: [1,3,5,6], 5
输出: 2
示例 2:

输入: [1,3,5,6], 2
输出: 1
示例 3:

输入: [1,3,5,6], 7
输出: 4
示例 4:

输入: [1,3,5,6], 0
输出: 0

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/search-insert-position
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

# 分析

很直截了当的二分

当然可以用线性查找，当前值大于等于目标时，这个位置就是应该插入的位置

```python
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        for i in range(len(nums)):
            if nums[i] >= target:
                return i
        return len(nums)

```

可以用二分查找进一步缩短时间，关键是数据中没有需要插入时，返回的索引。

当二分查找结束时left = right+1，在left==right的位置处是不相等的，如果此时这个位置的值比target小，那么left+1，而要插入的值也正是这个位置；当此时这个位置的值比target大，那么left不变,right-1，而插入后的位置就是现在left所指的位置，所以最终总是返回left的索引即可

```c++
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i = 0, j = nums.size()-1;
        while(i<=j){
            int mid = (i+j)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target)
                i++;
            else
                j--;
        }
        return i;
    }
};
```




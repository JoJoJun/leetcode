# 搜索旋转排序数组

假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。

你可以假设数组中不存在重复的元素。

你的算法时间复杂度必须是 O(log n) 级别。

> 示例 1:
>
> 输入: nums = [4,5,6,7,0,1,2], target = 0
> 输出: 4
> 示例 2:
>
> 输入: nums = [4,5,6,7,0,1,2], target = 3
> 输出: -1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/search-in-rotated-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

姐姐题81，有重复元素的螺旋旋转排序数组

# 分析

这里关键在于旋转后，mid的前后总有一个是有序的

根据有序的部分来判断下一步分划分

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()<1)return -1;
        if(nums.size()==1)
            return target == nums[0]?0:-1;
        int l = 0, r = nums.size()-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid]==target)return mid;
            if(nums[0]<=nums[mid]){
                if(target>=nums[0] && target<nums[mid])
                    r = mid-1;
                else
                    l = mid+1;
            }
            else{
                if(target>=nums[mid] && target<=nums[nums.size()-1])
                    l = mid+1;
                else
                    r = mid-1;
            }

        }
        return -1;
    }
};
```


# 搜索旋转排序数组 II

假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,0,1,2,2,5,6] 可能变为 [2,5,6,0,0,1,2] )。

编写一个函数来判断给定的目标值是否存在于数组中。若存在返回 true，否则返回 false。

> 示例 1:
>
> 输入: nums = [2,5,6,0,0,1,2], target = 0
> 输出: true
> 示例 2:
>
> 输入: nums = [2,5,6,0,0,1,2], target = 3
> 输出: false
> 进阶:
>
> 这是 搜索旋转排序数组 的延伸题目，本题中的 nums  可能包含重复元素。
> 这会影响到程序的时间复杂度吗？会有怎样的影响，为什么？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

# 分析

当有重复数字时，不好保证到底哪边是有序的，可以在之前的基础上，让左右两个指针都跳过重复的数字，其他继续：

```cpp
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size()<1)return false;
        if(nums.size() == 1)return nums[0]==target;
        int l =0, r = nums.size()-1;
        while(l<=r){
            while(l<r && nums[l]==nums[l+1])l++;
            while(l<r && nums[r]==nums[r-1])r--;
            int mid = l +(r-l)/2;
            if(nums[mid]==target)
                return true;
            if(nums[l]<=nums[mid]){
                if(target>=nums[l] && target<nums[mid])
                    r = mid-1;
                else
                    l = mid+1;
            }
            else {
                if(target>nums[mid]&& target<=nums[r])
                    l = mid+1;
                else
                    r = mid-1;
            }
        }
        return false;
    }
};
```

其实用来判断是否有序是left和mid值的大小，只有当两者相等时才难以判断。也可以当二者相等时简单的让left++，也相当于跳过了重复项

```java
class Solution {
    public boolean search(int[] nums, int target) {
        int size = nums.length;
        if(size == 0)return false;
        if(size == 1)return target == nums[0];
        int left = 0, right = size-1;
        while(left <= right){
            int mid = left + (right-left)/2;
            if(nums[mid]==target)
                return true;
            if(nums[mid]==nums[left]){
                left ++;
                continue;
            }
            else if(nums[left]<nums[mid]){
                if(target>= nums[left] && target<nums[mid])
                    right = mid-1;
                else
                    left = mid+1;
            }
            else{
                if(target>nums[mid] && target<= nums[right])
                    left= mid+1;
                else
                    right = mid - 1;
            }
        }
        return false;
    }
}
```


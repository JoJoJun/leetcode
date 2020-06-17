# 寻找旋转排序数组中的最小值

假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

请找出其中最小的元素。

你可以假设数组中不存在重复元素。

> 示例 1:
>
> 输入: [3,4,5,1,2]
> 输出: 1
> 示例 2:
>
> 输入: [4,5,6,7,0,1,2]
> 输出: 0

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

# 分析

当然可以线性查找真个数组的最小值

也相当于找找区间点，最好使用while不带等号，left right选择性+-1，

```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums[0]<nums[nums.size()-1])return nums[0];
        int l = 0, r = nums.size()-1;
        while(l<r){
            int mid = l+(r-l)/2;
            if(nums[mid]<nums[r])
                r = mid;
            else
                l = mid+1;
        }
        return nums[l];
    }
};
```




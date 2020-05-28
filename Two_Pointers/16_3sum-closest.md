# 最接近的三数之和

给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.

与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum-closest
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

# 分析

和三数之和基本一样，甚至时间上要求还低一点。

仍然是固定一个，另外两个做右指针移动。每次判断是否更接近了一点

# 代码

```java
class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int i,j,k;
        int ans = nums[0]+nums[1]+nums[2];
        for(i = 0;i<nums.length;i++){
            if(i!=0 && nums[i]==nums[i-1])continue;
            j = i+1;
            k = nums.length-1;
            while(j<k){
                int temp = nums[i]+nums[j]+nums[k];
                
                if(Math.abs(temp-target)<Math.abs(ans-target))
                    ans = temp;
                if(temp < target)
                j++;
                else if(temp>target)
                k--;
                else return target;
            }
        }
        return ans;
    }
}
```



C++

```cpp
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        int i,j,k;
      
        sort(nums.begin(),nums.end());
        int ans=nums[0]+nums[1]+nums[2];
        for(int i = 0;i<len;i++){
            if(i != 0 && nums[i]==nums[i-1])continue;
            j = i+1;k = len-1;
            while(j<k){
                int temp = nums[i]+nums[j]+nums[k];
                if(abs(target-temp)<abs(target-ans)){
                    ans = temp;
                }
                if(temp<target)
                j++;
                else if(temp>target)
                k--;
                else return target;
            }
        }
        return ans;
    }
};
```


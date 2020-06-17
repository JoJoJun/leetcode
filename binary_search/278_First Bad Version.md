# 第一个错误的版本

你是产品经理，目前正在带领一个团队开发新的产品。不幸的是，你的产品的最新版本没有通过质量检测。由于每个版本都是基于之前的版本开发的，所以错误的版本之后的所有版本都是错的。

假设你有 n 个版本 [1, 2, ..., n]，你想找出导致之后所有版本出错的第一个错误的版本。

你可以通过调用 bool isBadVersion(version) 接口来判断版本号 version 是否在单元测试中出错。实现一个函数来查找第一个错误的版本。你应该尽量减少对调用 API 的次数。

示例:

给定 n = 5，并且 version = 4 是第一个错误的版本。

调用 isBadVersion(3) -> false
调用 isBadVersion(5) -> true
调用 isBadVersion(4) -> true

所以，4 是第一个错误的版本。 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/first-bad-version
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

# 分析

这相当于是寻找左侧边界，或者说右侧第一个

当中间是好版本时，说明整个左侧都不可能有问题，left = mid+1；当中间是坏版本时，它自己可能是第一个坏了的版本，但它之后肯定不可能是我们要找的值，所以在闭区间找的话就是right = mid

while中没有等号，最后是当left=right时返回

```cpp
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int i = 1, j = n;
        while(i<j){
            int mid = i + (j-i)/2;
            bool ans = isBadVersion(mid);
            if(!ans)
                i = mid+1;
            else
                j = mid;
        }
        return i;
    }
};
```

用题解里给的统一的方法，while带等号，left,right全部修改，只需要注意最后的返回情况，此时left = right+1：

```java
/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */

public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        int left = 1, right = n;
        while(left<=right){
            int mid = left + (right-left)/2;
            if(isBadVersion(mid))
                right = mid-1;
            else
                left = mid+1;
        }
        if(left>n)return n;
        return left;
    }
}
```


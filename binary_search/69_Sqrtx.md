# x的平方根

实现 int sqrt(int x) 函数。

计算并返回 x 的平方根，其中 x 是非负整数。

由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

> 示例 1:
>
> 输入: 4
> 输出: 2
> 示例 2:
>
> 输入: 8
> 输出: 2
> 说明: 8 的平方根是 2.82842..., 
>      由于返回类型是整数，小数部分将被舍去。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sqrtx
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

# 分析

还是查找问题，找到一个数，比它大的数的平方会超过target。

这里就需要注意不要超过数值上限，用除法判断比用乘法保险。

可以顺序从1开始找，也可以用二分。用二分相当于找的是右区间的最小的那个，判断条件需要注意

C++

```cpp
class Solution {
public:
    int mySqrt(int x) {
        if(x == 0 || x == 1)return x;
        int min = 0, max = INT_MAX/2;
        while(max - min >1){
            int mid = (max + min)/2;
            if(x/mid == mid)
                return mid;
            else if(x/mid<mid)
                max = mid;
            else 
                min = mid;
        }
        return min;
    }
};
```



还可以用时间上慢一点但是更好理解的方式，就是不着急返回，只要mid*mid<=x就一直left = mid+1并且记录此时的mid，直到最后返回最后一个满足条件的就可以

```java
class Solution {
    public int mySqrt(int x) {
        if(x==0 || x== 1)return x;
        int left = 1, right = x;
        int ans = -1;
        while(left<=right){
            int mid = left +(right-left)/2;
            if(x/mid >= mid){
                ans = mid;
                left = mid+1;
            }
            else 
                right = mid-1;
         
        }
        return ans;
    }
}
```





除了用二分，还可以利用数学变化
$$
\sqrt(x) = x^{\frac{1}{2}} = {(e^{\ln{x}})}^{\frac{1}{2}}=e^{\frac{1}{2}\ln{x}}
$$
不过由于浮点运算存在误差，所以最后要判断一下,ans和ans+1哪一个更合适：

```python
class Solution:
    def mySqrt(self, x: int) -> int:
        if x==0 or x == 1:
            return x
        ans = int(math.exp(0.5 * math.log(x)))
        return ans+1 if (ans+1)*(ans+1)<=x else ans
```


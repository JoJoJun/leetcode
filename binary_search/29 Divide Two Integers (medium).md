# 两数相除

给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。

返回被除数 dividend 除以除数 divisor 得到的商。

整数除法的结果应当截去（truncate）其小数部分，例如：truncate(8.345) = 8 以及 truncate(-2.7335) = -2

 

> 示例 1:
>
> 输入: dividend = 10, divisor = 3
> 输出: 3
> 解释: 10/3 = truncate(3.33333..) = truncate(3) = 3
> 示例 2:
>
> 输入: dividend = 7, divisor = -3
> 输出: -2
> 解释: 7/-3 = truncate(-2.33333..) = -2


提示：

被除数和除数均为 32 位有符号整数。
除数不为 0。
假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231,  231 − 1]。本题中，如果除法结果溢出，则返回 231 − 1。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/divide-two-integers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

# 分析

可以理解为找一个数x，让x*divisor<=dividend，注意处理一下最大值的溢出

还是左区间最后一个，和278、69都比较像，不过要处理一下正负号

```cpp
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MAX && abs(divisor)==1)return divisor>0?INT_MAX:INT_MIN;
        if(dividend == INT_MIN && abs(divisor)==1) return divisor<0?INT_MAX:INT_MIN;
        int minus = ((dividend>0 && divisor<0)||(dividend<0 && divisor>0))?true:false;
        divisor =abs(divisor);
        dividend = abs(dividend);
        long long i = 1, j = dividend;
        while(i<=j){
            long long mid = i + (j-i)/2;
            if(mid * divisor < dividend)
                i= mid+1;
            else
                j = mid-1;
        }
        if(i * divisor == dividend)
            return minus==true?-1*i:i;
        else    
            return minus == true?-1*(i-1):(i-1);
    }
};
```



对比，278的核心：

```cpp
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

对比69

```cpp
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


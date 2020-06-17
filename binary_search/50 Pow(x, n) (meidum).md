# Pow(x, n)

实现 pow(x, n) ，即计算 x 的 n 次幂函数。

示例 1:

输入: 2.00000, 10
输出: 1024.00000
示例 2:

输入: 2.10000, 3
输出: 9.26100
示例 3:

输入: 2.00000, -2
输出: 0.25000
解释: 2-2 = 1/22 = 1/4 = 0.25
说明:

-100.0 < x < 100.0
n 是 32 位有符号整数，其数值范围是 [−231, 231 − 1] 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/powx-n
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

# 分析

很直接的求幂运算，可以用快速幂，用到二分的思想

可以用递归的方法：



![1592398125977](C:\Users\zzj\AppData\Roaming\Typora\typora-user-images\1592398125977.png)

```cpp
class Solution {
public:
    double quickMul(double x, long long N) {
        if (N == 0) {
            return 1.0;
        }
        double y = quickMul(x, N / 2);
        return N % 2 == 0 ? y * y : y * y * x;
    }

    double myPow(double x, int n) {
        long long N = n;
        return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
    }
};

```

时间复杂度为递归的深度O(logn)空间也是O(logn)

也可以用迭代的方法，从左到右迭代，关键要知道什么时候需要单独在乘一个x。

![1592398464520](C:\Users\zzj\AppData\Roaming\Typora\typora-user-images\1592398464520.png)

```cpp
class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        for(int i = n;i!=0;i/=2){
            if(i%2!=0)
                res *= x;
            x*=x;
        }
        return n<0?1/res:res;
    }
};
```

注意要考虑n为负数的情况
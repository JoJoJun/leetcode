

# 平方数之和

给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a2 + b2 = c。

> 示例1:
>
> 输入: 5
> 输出: True
> 解释: 1 * 1 + 2 * 2 = 5
>
> 示例2:
>
> 输入: 3
> 输出: False

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-of-square-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

# 分析

双指针 左右

最大就到算术平方根了，在大会超出int上限

和求和是一种问题,只不过这里是可以去到同一个数的

另外不要去判断i*i+j *j ，会很容易超出范围，而是判断差

# Code

C++ 和java也就bool 和Boolean的区别

```cpp
class Solution {
public:
    bool judgeSquareSum(int c) {
        int i = 0, j = sqrt(c);
        while(i<=j){
            if(i*i == c-j*j)
                return true;
            else if(i*i <c-j*j)
                i++;
            else 
             j--;
        }
        return false;
    }
};
```

```java
class Solution {
    public boolean judgeSquareSum(int c) {
        int i = 0, j = (int)Math.sqrt(c);
        while(i<=j){
            if(i*i == c-j*j)
                return true;
            else if(i*i < c-j*j)
                i++;
            else
                j--;
        }
        return false;
    }
}
```

java是不能默认把int转为double的，得自己强制转化
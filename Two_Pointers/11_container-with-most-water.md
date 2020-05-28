# 盛水最多的容器

给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器，且 n 的值至少为 2。

 



图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。

 

示例：

输入：[1,8,6,2,5,4,8,3,7]
输出：49

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/container-with-most-water
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

# 分析

也是左右双指针的经典题了，关键是指针移动规则

面积是底*高 底显然是两个坐标之差，随着指针的移动只会越来愈小；

高是两者中更小的一个。

那么只有下一条边是比较高的时候，面积才有可能增大。如果移动当前已经高的指针，面积一定会变小或者不变，因为另一条的矮边是限制。

所以总是要移动当前的矮边，才有可能让面积变大

# 代码

C++ 

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size()-1;
        int maxsum = 0;
        while(i<j){
            int hei = min(height[i],height[j]);
            int wide = j-i;
            int sum = hei* wide;
            if(sum > maxsum)
                maxsum = sum;
            if(height[i]<height[j])i++;
            else j--;
        }
        return maxsum;
        
    }
};

```



java

1 java中的length属性是针对数组说的,比如说你声明了一个数组,想知道这个数组的长度则用到了length这个属性.

2 java中的length()方法是针对字符串String说的,如果想看这个字符串的长度则用到length()这个方法.

3.java中的size()方法是针对泛型集合说的,如果想看这个泛型(array)有多少个元素,就调用此方法来查看!

```java
class Solution {
    public int maxArea(int[] height) {
        int i = 0, j = height.length-1;
        int ans = 0;
        while(i<j){
            int h = Math.min(height[i],height[j]);
            int w = j-i;
            if(h*w>ans)
                ans = h*w;
            if(height[i]<height[j])i++;
            else j--;
        }
        return ans;
    }
}
```


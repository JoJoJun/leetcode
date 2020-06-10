# 快乐数

编写一个算法来判断一个数 n 是不是快乐数。

「快乐数」定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。如果 可以变为  1，那么这个数就是快乐数。

如果 n 是快乐数就返回 True ；不是，则返回 False 。

 

示例：

输入：19
输出：true
解释：
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/happy-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

# 分析

其实这个和链表有没有环是相似的。可以用set来表示是否出现了重复，也可以用快慢指针

# 代码

C++ 集合思路

```cpp
class Solution {
public:
    bool isHappy(int n) {
        if(n==1)return true;
        unordered_set<int>res;
        while(true){
            if(n == 1){
                return true;
            }
            else{
                int sum = 0;
                while(n){
                    int mod = n%10;
                    sum += mod*mod;
                    n/=10;
                }
                n = sum;
                if(res.find(n)!=res.end())return false;
                res.insert(n);
            }
        }
    }
};
```



C++  快慢指针

```cpp
class Solution {
public:
    int getNext(int n){
        int sum = 0;
        while(n){
            int mod = n%10;
            sum += mod*mod;
            n /=10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow = n, fast = getNext(n);
        while(fast != 1 && fast!= slow){
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }
       return fast == 1;
    }
};
```


# 反转字符串中的元音字符

编写一个函数，以字符串作为输入，反转该字符串中的元音字母。

> 示例 1:
>
> 输入: "hello"
> 输出: "holle"
> 示例 2:
>
> 输入: "leetcode"
> 输出: "leotcede"
> 说明:
> 元音字母不包含字母"y"。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-vowels-of-a-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

# 分析

反转字符串很适合用双指针，一个指头一个指尾，遇到元音交换；

类似的，还可以转换奇偶数的位置、判断回文串、整个翻转等，只是判断条件有变化

# 代码

python3

注意Python的字符串是不可变的，得先转化成list，再转化成字符串

```python
class Solution:
    def reverseVowels(self, s: str) -> str:
        vowels = set(['a','e','i','o','u','A','E','I','O','U'])
        length = len(s)
        i = 0
        j = length-1
        lists = list(s)
        while i<=j:
            if lists[i] in vowels and lists[j] in vowels:
                t = lists[i]
                lists[i] = lists[j]  
                lists[j] = t              
                i+=1
                j-=1
            if i<length and lists[i] not in vowels:
                i+=1
            if j>=0 and lists[j] not in vowels:
                j -=1
        return ''.join(lists)
```

C++

string.find()

```cpp
class Solution {
public:
    string reverseVowels(string s) {
        string vowel ="aeiouAEIOU";
        int i = 0, j = s.length()-1;
        while(i<j){
            while(vowel.find(s[i])==-1 && i<j)
            i++;
            while(vowel.find(s[j])==-1 && i<j)
            j--;
            if(i<j){
            swap(s[i],s[j]);
            i++;
            j--;
            }
        }
        return s;
    }
};
```


# 描述
括号生成
数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。


>示例：
输入：n = 3
输出：[
       "((()))",
       "(()())",
       "(())()",
       "()(())",
       "()()()"
     ]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/generate-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
# 分析
很明显也具备用回溯的特征，决策树每一层是上层的(或)后再放(或)，不过放)要求其数量不能大于已有的(
```
backtrack:
  判断条件 --> 左右括号数都等于n
  列举所有选项  --> ( or )
  判断选项是否合法  --> num < n && right < left
  更新状态  --> 左右括号数量 当前括号情况
  step forward
  恢复状态
 ```
# 代码
```cpp
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string temp = "";
        vector<string>ans;
        backtrack(0,0,temp,ans,n);
        return ans;
    }
    void backtrack(int left, int right,string temp, vector<string>&ans, int n){
        if(left == n && right == n){
            ans.push_back(temp);
        }
         if(left < n){
             left ++;
             temp += "(";
             backtrack(left,right,temp,ans,n);
             left --;
             temp.pop_back();
         }
         if(right < n && right < left){
             right ++;
             temp += ')';
             backtrack(left,right,temp,ans,n);
             right --;
             temp.pop_back();
         }
    }
};
```

试着用java，（Java的字符串就不如C++方便
```java
class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> ans = new ArrayList();
        StringBuilder temp = new StringBuilder();
        backtrack(0,0,temp,ans,n);
        return ans;
    }
    void backtrack(int left, int right, StringBuilder temp, List<String>ans,int n){
        if(left == n && right == n){
            ans.add(temp.toString());
        }
        if(left < n){
            left ++;
            temp.append("(");
            backtrack(left,right,temp,ans,n);
            left --;
            temp.deleteCharAt(temp.length() - 1);
        }
        if (right < n && right < left){
            right ++;
            temp.append(")");
            backtrack(left,right,temp,ans,n);
            right --;
            temp.deleteCharAt(temp.length()-1);
        }
    }
}
```

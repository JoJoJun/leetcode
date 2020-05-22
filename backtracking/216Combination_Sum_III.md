# 描述：
找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。
说明：
所有数字都是正整数。
解集不能包含重复的组合。 
>示例 1:
输入: k = 3, n = 7
输出: [[1,2,4]]
示例 2:
输入: k = 3, n = 9
输出: [[1,2,6], [1,3,5], [2,3,4]]

# 分析
//也就是相较 39 和 40 多了的条件是组合的长度必须为k个数，所以递归的时候如果超出了k个数就可以直接回退了
仍然满足前两道的递归思路：
```
backtrack:
   是否满足递归出口；
   列出所有选项 --> start-9
   选项是否合法  --> 和 size
   更新状态
   step forwrd
   恢复状态
```
避免重复也是体现在排序后，可选条件每次后移一个，保证向下递归时不会用到重复的数字

# Code
```cpp
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>temp;
        if(n<=0)return ans;
        if(n==1 && k==1){
            temp.push_back(1);
            ans.push_back(temp);
            return ans;
        }
        backtrack(1,n,k,temp,0,ans);
        return ans;

    }
   
    void backtrack(int start, int n, int k,vector<int>temp, int sum,vector<vector<int>>&ans){
        if(temp.size()==k && sum == n){
          ans.push_back(temp);
          return;
        }
        else if(temp.size()>k || sum>n)
        return;
        for(int i = start; i<=9;i++){
            if(i<=n && sum<n && temp.size()<k){
                temp.push_back(i);
                backtrack(i+1,n,k,temp,sum+i,ans);
                temp.pop_back();
            } 
        }
    }
};
```
java
要注意删除最后一个元素用索引
添加的是new ArrayList(temp)
```java
class Solution {
    int n;
    int k;
    List<List<Integer>> ans;
    public List<List<Integer>> combinationSum3(int k, int n) {
       ans = new ArrayList<>();
        List<Integer>temp = new ArrayList();
        if(n<=0 || k<=0)
        return ans;
        if(n==1 && k==1){
            temp.add(1);
            ans.add(temp);
            return ans;
        }
        this.n = n;
        this.k = k;
        backtrack(1,0,temp);
        return ans;
    }
    void backtrack(int start, int sum,List<Integer>temp){
        if(temp.size() == k && sum == n){
            this.ans.add(new ArrayList(temp));
        }
        else if(sum >n || temp.size()>k)
            return;
        for(int i = start; i<=9;i++){
            if(sum<n && temp.size()<k){
                temp.add(i);
                backtrack(i+1,sum+i,temp);
                temp.remove(temp.size()-1);
            }
        }
    }
}
```

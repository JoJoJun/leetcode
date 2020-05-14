# describe
给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

>示例:
输入: n = 4, k = 2
输出:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/combinations
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
# analysis
```
backtrack:
  判断条件 --> 有k个数字了
  列举所有选项 --> start-n
  是否合法
  更新状态
  step forward
  恢复状态
```
# code
```cpp
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>temp;
        backtrack(1,n,k,temp,ans);
        return ans;
    }
    void backtrack(int start, int n, int k, vector<int>&temp, vector<vector<int>>&ans){
        if(temp.size()==k){
            ans.push_back(temp);
            return;
        }
        for(int i = start;i<=n;i++){
            temp.push_back(i);
            backtrack(i+1,n,k,temp,ans);
            temp.pop_back();
        }
    }
};
```
>ArrayList基于动态数组实现的非线程安全的集合；LinkedList基于链表实现的非线程安全的集合
对于随机index访问的get和set方法，一般ArrayList的速度要优于LinkedList。因为ArrayList直接通过数组下标直接找到元素；LinkedList要移动指针遍历每个元素直到找到为止。
新增和删除元素，一般LinkedList的速度要优于ArrayList。因为ArrayList在新增和删除元素时，可能扩容和复制数组；LinkedList实例化对象需要时间外，只需要修改指针即可。
按理说LinkedList应该更快才对，但是发现效率更低了

```java
class Solution {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> ans = new ArrayList();
        List<Integer> temp = new ArrayList();
        backtrack(1,k,n,temp,ans);
        return ans;
    }
    public void backtrack(int start ,int k, int n, List<Integer>temp, List<List<Integer>> ans){
        if(temp.size()==k){
            ans.add(new ArrayList(temp)); //注意这里不能直接加temp 啊 java好烦
            return;
        }
        for(int i = start; i<=n;i++){
            temp.add(i);
            backtrack(i+1,k,n,temp,ans);
            temp.remove(temp.size()-1);
        }
    }
}
```

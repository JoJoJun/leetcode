# leetcode-按类别
看了一些leetcode刷题指南，总结一下两个重点，一是最好按照类别刷题，总结思路；二是由易到难，不要产生太大挫败感。
另外最好集中时间强度大一点来刷；还可以每个题只预留固定的思考时间，做不出就wa掉看discuss。
先读懂题目，再想清楚过程（面试时也时要说清楚自己思路的），然后具体到代码。代码要注意bug-free，自己多想几个test case。


遂决定开一个repository记录该过程。
## backtrack
- [401 Binary Watch (easy)](https://leetcode-cn.com/problems/binary-watch/) √ 
- [17 Letter Combinations of a Phone Number(medium)](https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/)√
- [22 Generate Parentheses(medium)](https://leetcode-cn.com/problems/generate-parentheses/) √
- [39 Combination Sum (medium)](https://leetcode-cn.com/problems/combination-sum/) √
- [40 Combination Sum II (medium)](https://leetcode-cn.com/problems/combination-sum-ii/)
- [46 Permutations (medium)](https://leetcode-cn.com/problems/permutations/) √
- [47 Permutations II (medium)](https://leetcode-cn.com/problems/permutations-ii/) √
- [77 Combinations (medium)](https://leetcode-cn.com/problems/combinations/) √
- [78 Subsets(medium)](https://leetcode-cn.com/problems/subsets/)  √
- [79 Word Search(medium)](https://leetcode-cn.com/problems/word-search/) √
- [90 Subsets II (medium)](https://leetcode-cn.com/problems/subsets-ii/) √
- [93 Restore IP Addresses(medium)](https://leetcode-cn.com/problems/restore-ip-addresses/)  √
- [130 surrounded-regions (medium)](https://leetcode-cn.com/problems/surrounded-regions/) √
- [131 Palindrome Partitioning    (medium)](https://leetcode-cn.com/problems/palindrome-partitioning/) √
- [200 Number of Islands （medium）](https://leetcode-cn.com/problems/number-of-islands/)  √
- [216 Combination Sum III (medium)](https://leetcode-cn.com/problems/combination-sum-iii/)  √
- 254 	Factor Combinations (medium) --locked
- [306 Additive Number(medium)](https://leetcode-cn.com/problems/additive-number/) √
- 357 Count Numbers with Unique Digits(medium)
- 547 Friend Circles (medium)
- 51 N-Queens (hard)
- 132 Palindrome Partitioning    (hard)
- 212 Word Search II (hard)


## DFS /二叉树
> the difference between dfs and backtracking:Backtracking is a more general purpose algorithm.  Depth-First search is a specific form of backtracking related to searching tree structures. From Wikipedia:
> DFS magic spell: 1]push to stack, 2] pop top , 3] retrieve unvisited neighbours of top, push them to stack 4] repeat 1,2,3 while stack not empty. -- https://medium.com/leetcode-patterns/leetcode-pattern-1-bfs-dfs-25-of-the-problems-part-1-519450a84353
>
> 对于二叉树的问题，明确一个节点要做什么，剩下的递归下去
>
> ```java
> void traverse(TreeNode root) {
>     // root 需要做什么？在这做。
>     // 其他的不用 root 操心，抛给框架
>     traverse(root.left);
>     traverse(root.right);
> }
> 
> 作者：labuladong
> 链接：https://leetcode-cn.com/problems/same-tree/solution/xie-shu-suan-fa-de-tao-lu-kuang-jia-by-wei-lai-bu-/
> 来源：力扣（LeetCode）
> ```
>

注意很多时候需要判断左子树和右子树是否为空

- [100 Same Tree  (easy)](https://leetcode-cn.com/problems/same-tree/submissions/) 相同的树 √
- [101 Symmetric Tree  (easy)](https://leetcode-cn.com/problems/symmetric-tree/) 判断对称二叉树 √
- [104 Maximum Depth of Binary Tree(easy)](https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/) 二叉树的最大深度 √
- [108	Convert Sorted Array to Binary Search Tree (easy)](https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/)  将有序数组转化为二叉搜索树   其实也是个二分  二分搜索树 √
- [110 Balanced Binary Tree(easy)](https://leetcode-cn.com/problems/balanced-binary-tree/) 平衡二叉树判断√
- [111 树的最小深度(easy) ](https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/) √
- [112 Path Sum (easy)](https://leetcode-cn.com/problems/path-sum/)√
- [226 翻转二叉树 （easy）](https://leetcode-cn.com/problems/invert-binary-tree/)√
- [235 二叉搜索树的最近公共祖先（easy）](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/) √
- [257	Binary Tree Paths (easy)](https://leetcode-cn.com/problems/binary-tree-paths/)二叉树的所有路径 backtrack  √
- 270 最接近的二叉搜索树值（easy） locked
- [404 左叶子之和（easy）](https://leetcode-cn.com/problems/sum-of-left-leaves/) √
- [543  	Diameter of Binary Tree 二叉树的直径（easy）](https://leetcode-cn.com/problems/diameter-of-binary-tree/) √
- [94 Binary Tree Inorder Traversal    (medium) ](https://leetcode-cn.com/problems/binary-tree-inorder-traversal/)二叉树的中序遍历 √
- [98 Validate Binary Search Tree](https://leetcode-cn.com/problems/validate-binary-search-tree/) 验证二叉搜索树（medium）√
- [105 前序中序构造二叉树 （medium）](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/) √
- [106 中序后序构造二叉树 （medium）](https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/) 105 & 106在树的大小+-1上有坑，注意举个例子判断，这里要-1的 √
- [109 Convert Sorted List to Binary Search Tree (medium) ](https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/)将有序链表转化为平衡的二叉搜索树  相比108只是多了找链表的中间节点 √
- [113 Path Sum II （medium）](https://leetcode-cn.com/problems/path-sum-ii/)  √
- [114 二叉树展开为列表 （medium）](https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/)√
- [116 Populating Next Right Pointers in Each Node 填充同一层的兄弟节点(medium)](https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node/) 可以用层序遍历，也可以用DFS √
- [117 	Populating Next Right Pointers in Each Node II  填充每一个节点的下一个右侧节点指针 非满二叉树  （medium）](https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node-ii/)√
- [129 Sum Root to Leaf Numbers (medium)](https://leetcode-cn.com/problems/sum-root-to-leaf-numbers/) 求根到叶子节点数字之和 递归 √
- [222 Count Complete Tree Nodes(medium)](https://leetcode-cn.com/problems/count-complete-tree-nodes/) 完全二叉树的节点个数 √
- [236 二叉树的最近公共节点(medium)](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/) √
- 323 Number of Connected Components in an Undirected Graph(medium) 无向图中连通分量的数目  locked
- 124 	Binary Tree Maximum Path Sum  (hard)



## BFS

- 107 Binary Tree Level Order Traversal II (easy)
- [102 二叉树层序遍历（medium）](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/)
- 103 Binary Tree Zigzag Level Order Traversal (medium)
- 207 Course Schedule(medium)
- [199	Binary Tree Right Side View  (medium)  ](https://leetcode-cn.com/problems/binary-tree-right-side-view/)  二叉树的右视图 层序遍历
- 210 Course Schedule II(medium)
- 130 Surrounded Regions(medium)
- 286 Walls and Gates(medium)

## 二分
参考[题解](https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/solution/er-fen-cha-zhao-suan-fa-xi-jie-xiang-jie-by-labula/)

几种常见情况：搜索一个数、搜索左区间、搜索右区间

![1592030582368](C:\Users\zzj\AppData\Roaming\Typora\typora-user-images\1592030582368.png)

为了防止溢出，最好用

```cpp
int mid = left + (right - left) / 2;
```

搜索一个数时，区间是[0,size()-1]，是整个的闭区间，while的条件也是<=，因为这样最终才会得到空区间；

当寻找符合条件的左边最后一个时，搜索的是左闭右开区间[0,size()),while中的条件也是<，每次是mid+1或mid。也可以用闭区间的，只是最后需要检查是否越界

统一的话区别只在是否返回以及最后循环外返回的检查

- [35 Search Insert Position (easy)](https://leetcode-cn.com/problems/search-insert-position/)
- [69 Sqrt(x) (easy)](https://leetcode-cn.com/problems/sqrtx/)
- [278 First Bad Version (easy)](https://leetcode-cn.com/problems/first-bad-version/) -- 左区间
- [29 Divide Two Integers (medium)](https://leetcode-cn.com/problems/divide-two-integers/) 注意INT范围
- [33 Search in Rotated Sorted Array (medium)](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/)
- [50 Pow(x, n) (meidum)](https://leetcode-cn.com/problems/powx-n/)
- [74 Search a 2D Matrix (medium)](https://leetcode-cn.com/problems/search-a-2d-matrix/)
- [81 Search in Rotated Sorted Array II (medium) ](https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/)相比33，数组中存在重复数字
- [153 Find Minimum in Rotated Sorted Array(medium)](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/)
- [162 Find Peak Element (medium)](https://leetcode-cn.com/problems/find-peak-element/)
- [275 H-Index II (medium)](https://leetcode-cn.com/problems/h-index-ii/)
- 378 有序矩阵中第k小的元素 medium
## 滑动窗口型
见大神的一篇(https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/solution/hua-dong-chuang-kou-tong-yong-si-xiang-jie-jue-zi-/)
初始左指针（left）和右指针（right）都指向0
右指针不断向右移动
当满足窗口大小时候，进行相应的处理，这个和过程中需要left向右移动
- 325 Maximum Sum Subarray of Size K (easy)
- Smallest Subarray with a given sum (easy) 209 Minimum Size Subarray Sum 
- [3  Longest Substring Without Repeating Characters (medium)](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/)  √
 - 159 Longest Substring with At Most Two Distinct Characters
 - 340 Longest Substring with At Most K Distinct Characters 
 - 395 Longest Substring with At Least K Repeating Characters  
 - [438 Find All Anagrams in a String (medium)](https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/) √
- 904 Fruits into Baskets (medium)
- 567 Permutation in String (medium) 固定窗口
- 1052 Grumpy Bookstore Owner  （medium）固定窗口
- 424	Longest Repeating Character Replacement 替换后的最长重复字符 (medium)
- 978 Longest Turbulent Subarray    （medium）
- Longest Subarray with Ones after Replacement (hard)
- 76 Minimum Window Substring （hard）
- 239 Sliding Window Maximum (hard)
- 480	Sliding Window Median  (hard)
- 992 Subarrays with K Different Integers 	K 个不同整数的子数组 (hard)

##  双指针、快慢指针
见[大神题解：](https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/solution/hua-dong-chuang-kou-tong-yong-si-xiang-jie-jue-zi-/%E5%8F%8C%E6%8C%87%E9%92%88%E6%8A%80%E5%B7%A7.md)
> Remove Duplicates (easy)
Squaring a Sorted Array (easy)
Triplet Sum to Zero (medium)
Triplet Sum Close to Target (medium)
Triplets with Smaller Sum (medium)
Subarrays with Product Less than a Target (medium)

- [26 Remove Duplicates from Sorted Array (easy)](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/)  √
- [88 Merge Sorted Array (Easy)](https://leetcode-cn.com/problems/merge-sorted-array/) √
- [167. Two Sum II - Input array is sorted (Easy)](https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/) √
- [345 Reverse Vowels of a String (Easy)](https://leetcode-cn.com/problems/reverse-vowels-of-a-string/) √
- [633 Sum of Square Numbers (Easy)](https://leetcode-cn.com/problems/sum-of-square-numbers/) √
- [680 Valid Palindrome II (Easy)](https://leetcode-cn.com/problems/valid-palindrome-ii/) √
- [11 Container With Most Water  (medium)](https://leetcode-cn.com/problems/container-with-most-water/) √
- [15 3Sum  (medium)](https://leetcode-cn.com/problems/3sum/) √
- [16 3Sum Closest    最接近三数只和 (medium)](https://leetcode-cn.com/problems/3sum-closest/) √
- [18 4Sum (medium)](https://leetcode-cn.com/problems/4sum/) √
- 209 长度最小的子数组 medium 可以用双指针 或者前缀和


 快慢指针
 > LinkedList Cycle (easy)
> Start of LinkedList Cycle (medium)

- [141 Linked List Cycle (Easy)](https://leetcode-cn.com/problems/linked-list-cycle/) √
- [160 Intersection of Two Linked Lists 相交链表 (easy)](https://leetcode-cn.com/problems/intersection-of-two-linked-lists/) √
- [202 Happy Number (easy)](https://leetcode-cn.com/problems/happy-number/) √
- [234 Palindrome Linked List  回文链表 (easy)](https://leetcode-cn.com/problems/palindrome-linked-list/) √
- [876 Middle of the LinkedList (easy)](https://leetcode-cn.com/problems/middle-of-the-linked-list/) √
- [19 Remove Nth Node From End of List 删除链表倒数第N个节点 (medium)](https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/) √
- [142 Linked List Cycle II(medium)](https://leetcode-cn.com/problems/linked-list-cycle-ii/) √
- [524 Longest Word in Dictionary through Deleting (Medium)](https://leetcode-cn.com/problems/longest-word-in-dictionary-through-deleting/) √


剑指offer 待补充

## Top K
- 215 Kth Largest Element in an Array    (medium)
- 230 Kth Smallest Element in a BST   (medium)
- 347 Top K Frequent Elements    (medium)



## 字符串

多数能用动态规划来解决

- 53 最大子序和 easy
- 121 买卖股票的最大利润 easy
- 5 最长回文子串 medium 
- 300 最长上升子序列 medium
- 516 最长回文子序列 medium
- 1143 最长公共子序列 medium
- 128 最长连续序列 hard

## 区间合并
- 21 	Merge Two Sorted Lists (easy)
- 88 Merge Sorted Array (easy)
- 56 Merge Intervals  (medium)
- 986 Interval List Intersections    (medium)
- 57 Insert Interval    (hard)
也包括多路归并：
- 215 	Kth Largest Element in an Array   (medium)
- 378	Kth Smallest Element in a Sorted Matrix   (medium)
- 23 Merge k Sorted Lists    (hard)
## 链表翻转
- 206 Reverse Linked List  (easy)
- 92 Reverse Linked List II    (medium)
- 328 Odd Even Linked List (medium)
## 循环排序
> 一般涉及排好序的（局部有序），尤其是在排序过/翻转过的数组中找最小的、丢失的、重复的等等
- 268 Missing Number  (easy)
- 287 	Find the Duplicate Number (medium)

## 2 heaps
> 很适合用优先队列 中位数 最大最小数
- 295 Find Median from Data Stream   (hard)
- 480 Sliding Window Median  (hard)
- 剑指
## 拓扑排序
- 207 Course Schedule   (medium)
- 210 Course Schedule II   (medium)
- 621 Task Scheduler    (medium)
## DP
待补充

## 位运算
-89 Gray code (medium)

## 常见数组题

- 215 数组中第K大元素 medium  可以是二分、快排、堆排序






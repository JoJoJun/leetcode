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


## DFS 
> the difference between dfs and backtracking:Backtracking is a more general purpose algorithm.  Depth-First search is a specific form of backtracking related to searching tree structures. From Wikipedia:
DFS magic spell: 1]push to stack, 2] pop top , 3] retrieve unvisited neighbours of top, push them to stack 4] repeat 1,2,3 while stack not empty. -- https://medium.com/leetcode-patterns/leetcode-pattern-1-bfs-dfs-25-of-the-problems-part-1-519450a84353

- 100 Same Tree  (easy)
- 101 Symmetric Tree  (easy)
- 104 Maximum Depth of Binary Tree(easy)
- 108	Convert Sorted Array to Binary Search Tree (easy)
- 257	Binary Tree Paths (easy)
- 797 	All Paths From Source to Target (medium)
- 110 Balanced Binary Tree(easy)
- 112 Path Sum (easy)
- 113 Path Sum II （easy）
- 543  	Diameter of Binary Tree 二叉树的直径（easy）
- 94 Binary Tree Inorder Traversal    (medium)
- 98 Validate Binary Search Tree 验证二叉搜索树（medium）
- 109 Convert Sorted List to Binary Search Tree (medium)
- 114 Flatten Binary Tree to Linked List  (medium)
- 105 Construct Binary Tree from Preorder and Inorder Traversal  从前序与中序遍历序列构造二叉树(medium)
- 106 Construct Binary Tree from Inorder and Postorder Traversal 从中序与后序遍历序列构造二叉树 (medium)
- 114 Flatten Binary Tree to Linked List （medium）
- 116 Populating Next Right Pointers in Each Node 填充同一层的兄弟节点(medium)
- 117 	Populating Next Right Pointers in Each Node II   （medium）
- 129 Sum Root to Leaf Numbers (medium)
- 144 Binary Tree Preorder Traversal (medium)
- 199	Binary Tree Right Side View  (medium)
- 222 Count Complete Tree Nodes(medium)
- 323 Number of Connected Components in an Undirected Graph(medium)
- 124 	Binary Tree Maximum Path Sum  (hard)

## BFS
- 101 Symmetric Tree (easy)
- 107 Binary Tree Level Order Traversal II (easy)
- 102 	Binary Tree Level Order Traversal   (medium)
- 103 Binary Tree Zigzag Level Order Traversal (medium)
- 207 Course Schedule(medium)
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

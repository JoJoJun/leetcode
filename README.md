# leetcode-按类别
看了一些leetcode刷题指南，总结一下两个重点，一是最好按照类别刷题，总结思路；二是由易到难，不要产生太大挫败感。
另外最好集中时间强度大一点来刷；还可以每个题只预留固定的思考时间，做不出就wa掉看discuss。
先读懂题目，再想清楚过程（面试时也时要说清楚自己思路的），然后具体到代码。代码要注意bug-free，自己多想几个test case。


遂决定开一个repository记录该过程。
## backtrack
- 401 Binary Watch (easy)
- 17 Letter Combinations of a Phone Number(medium)
- 22 Generate Parentheses(medium)
- [39 Combination Sum (medium)](https://leetcode-cn.com/problems/combination-sum/) √
- 40 Combination Sum II (medium)
- [46 Permutations (medium)](https://leetcode-cn.com/problems/permutations/) √
- [47 Permutations II (medium)](https://leetcode-cn.com/problems/permutations-ii/) √
- 60 Permutation Sequence(medium)
- 77 Combinations (medium)
- [78 Subsets(medium)](https://leetcode-cn.com/problems/subsets/)  √
- 79 Word Search(medium)
- 89 Gray Code(medium)
- [90 Subsets II (medium)](https://leetcode-cn.com/problems/subsets-ii/) √
- 93 Restore IP Addresses(medium)
- 131 Palindrome Partitioning    (medium)
- 200 Number of Islands （medium）
- 211 	Add and Search Word - Data structure design(medium)
- 212 Word Search II (medium)
- 216 Combination Sum III (medium)
- 254 	Factor Combinations (medium)
- 306 Additive Number(medium)
- 357 Count Numbers with Unique Digits(medium)
- 547 Friend Circles (medium)
- 51 N-Queens (hard)
- 132 Palindrome Partitioning    (hard)

## DFS 
> the difference between dfs and backtracking:Backtracking is a more general purpose algorithm.  Depth-First search is a specific form of backtracking related to searching tree structures. From Wikipedia:
DFS magic spell: 1]push to stack, 2] pop top , 3] retrieve unvisited neighbours of top, push them to stack 4] repeat 1,2,3 while stack not empty. -- https://medium.com/leetcode-patterns/leetcode-pattern-1-bfs-dfs-25-of-the-problems-part-1-519450a84353

- 100 Same Tree  (easy)
- 101 Symmetric Tree  (easy)
- 104 Maximum Depth of Binary Tree(easy)
- 108	Convert Sorted Array to Binary Search Tree (easy)
- 	257	Binary Tree Paths (easy)
- 797 	All Paths From Source to Target (medium)
- 110 Balanced Binary Tree(easy)
- 112 Path Sum (easy)
- 113 Path Sum II （easy）
- 543  	Diameter of Binary Tree 二叉树的直径（easy）
- 94 Binary Tree Inorder Traversal    (medium)
- 109 Convert Sorted List to Binary Search Tree (medium)
- 114 Flatten Binary Tree to Linked List  (medium)
- 199	Binary Tree Right Side View  (medium)
- 98 Validate Binary Search Tree 验证二叉搜索树（medium）
- 144 Binary Tree Preorder Traversal (medium)
- 105 Construct Binary Tree from Preorder and Inorder Traversal  从前序与中序遍历序列构造二叉树(medium)
- 106 Construct Binary Tree from Inorder and Postorder Traversal 从中序与后序遍历序列构造二叉树 (medium)
- 114 Flatten Binary Tree to Linked List （medium）
- 	116 Populating Next Right Pointers in Each Node 填充同一层的兄弟节点(medium)
- 117 	Populating Next Right Pointers in Each Node II   （medium）
- 129 Sum Root to Leaf Numbers (medium)
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
- 35 Search Insert Position (easy)
- 69 Sqrt(x) (easy)
- 278 First Bad Version (easy)
- 29 Divide Two Integers (medium)
- 33 Search in Rotated Sorted Array (medium)
- 50 Pow(x, n) (meidum)
- 74 Search a 2D Matrix (medium)
- 81 Search in Rotated Sorted Array II (medium)
- 153 Find Minimum in Rotated Sorted Array(medium)
- 162 Find Peak Element (medium)
- 222 Count Complete Tree Nodes(medium)
- 275 H-Index II (medium)
## 滑动窗口型
初始左指针（left）和右指针（right）都指向0
右指针不断向右移动
当满足窗口大小时候，进行相应的处理，这个和过程中需要left向右移动
- 325 Maximum Sum Subarray of Size K (easy)
- Smallest Subarray with a given sum (easy) 209 Minimum Size Subarray Sum 
- Longest Substring with K Distinct Characters (medium)
 - 159 Longest Substring with At Most Two Distinct Characters
 - 340 Longest Substring with At Most K Distinct Characters 
 - 395 Longest Substring with At Least K Repeating Characters  
 - 438 Find All Anagrams in a String (medium)
- 904 Fruits into Baskets (medium)
- 567 Permutation in String (medium) 固定窗口
- 1052 Grumpy Bookstore Owner  （medium）固定窗口
- 3  Longest Substring Without Repeating Characters (medium)
- 424	Longest Repeating Character Replacement 替换后的最长重复字符 (medium)
- 978 Longest Turbulent Subarray    （medium）
- Longest Subarray with Ones after Replacement (hard)
- 76 Minimum Window Substring （hard）
- 239 Sliding Window Maximum (hard)
- 480	Sliding Window Median  (hard)
- 992 Subarrays with K Different Integers 	K 个不同整数的子数组 (hard)

##  双指针、快慢指针
> Remove Duplicates (easy)
Squaring a Sorted Array (easy)
Triplet Sum to Zero (medium)
Triplet Sum Close to Target (medium)
Triplets with Smaller Sum (medium)
Subarrays with Product Less than a Target (medium)
- 26 Remove Duplicates from Sorted Array (easy)
- 167. Two Sum II - Input array is sorted (Easy)
- 3 Longest Substring Without Repeating Characters (medium)
- 11 Container With Most Water  (medium)
- 15 3Sum  (medium)
- 16 3Sum Closest    最接近三数只和 (medium)
- 18 4Sum (medium)
- 633 Sum of Square Numbers (Easy)
- 345 Reverse Vowels of a String (Easy)
- 680 Valid Palindrome II (Easy)
- 88 Merge Sorted Array (Easy)
 快慢指针
 > LinkedList Cycle (easy)
> Start of LinkedList Cycle (medium)

- 141 Linked List Cycle (Easy)
- 524 Longest Word in Dictionary through Deleting (Medium)
- 234 Palindrome Linked List  回文链表 (easy)
- 141 Linked List Cycle   环形链表（easy）
- 142 Linked List Cycle II
- 160 Intersection of Two Linked Lists 相交链表 (easy)
- 19 Remove Nth Node From End of List 删除链表倒数第N个节点 (easy)
- 202 Happy Number (easy)
- 878 Middle of the LinkedList (easy)

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


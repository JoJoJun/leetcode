# 相交链表

编写一个程序，找到两个单链表相交的起始节点。

如下面的两个链表：



在节点 c1 开始相交。

 

示例 1：



输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
输出：Reference of the node with value = 8
输入解释：相交节点的值为 8 （注意，如果两个链表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为 [5,0,1,8,4,5]。在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。


示例 2：



输入：intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
输出：Reference of the node with value = 2
输入解释：相交节点的值为 2 （注意，如果两个链表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [0,9,1,2,4]，链表 B 为 [3,2,4]。在 A 中，相交节点前有 3 个节点；在 B 中，相交节点前有 1 个节点。


示例 3：



输入：intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
输出：null
输入解释：从各自的表头开始算起，链表 A 为 [2,6,4]，链表 B 为 [1,5]。由于这两个链表不相交，所以 intersectVal 必须为 0，而 skipA 和 skipB 可以是任意值。
解释：这两个链表不相交，因此返回 null。


注意：

如果两个链表没有交点，返回 null.
在返回结果后，两个链表仍须保持原有的结构。
可假定整个链表结构中没有循环。
程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/intersection-of-two-linked-lists
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

# 分析

如果用set来保存其中一个，然后遍历另一个链表，找是否有节点存在，时间复杂度和空间复杂度都是O(n)；当然也可以用两个stack来检查最后一个相同的点，因为相交之后的节点必然是一样的；



如果用双指针的话，就可以不用额外的空间来判断。分别遍历两个链表，找出较长的那个以及两者长度的差，让长的一方先走完这部分差值，那两者重合时就是相交的位置



# 代码

python 集合

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        listset = set()
        p = headA
        while p:
            listset.add(p)
            p = p.next
        p = headB
        while p:
            if p in listset:
                return p
            p = p.next
        return None

```

C++ 双指针

```cpp
class Solution {
public:
    int getLength(ListNode * head){
        ListNode * p = head;
        int l = 0;
        while(p!=NULL){
            l++;
            p = p->next;
        }
        return l;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL)return NULL;
        int la = getLength(headA);
        int lb = getLength(headB);
        ListNode* longone = headA;
        ListNode* shortone = headB;
        int diff = la-lb;
        if(la<lb){
            longone = headB;
            shortone = headA;
            diff = lb-la;
        }
        for(int i = 0;i<diff;i++)
        longone = longone->next;
        while(longone!=shortone && longone != NULL){
            shortone = shortone->next;
            longone = longone->next;
        }
        if(longone == shortone)return longone;
        else return NULL;
    }
};
```

有更简洁一点的代码，和这个的思路本质上一样，就不需要单独计算两个的长度了：

让两个一起走，先到达NULL的那个（A）回到另一个（B）的开头，然后继续一起走，直到另一个（B）也到结尾后重新指向它（A）的开头，然后重新一起走，直到结尾



代码简直简短的感人

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL )
        return NULL;
        ListNode * p = headA;ListNode* q = headB;
        while(p !=q){
            p = p==NULL?headB:p->next;
            q = q==NULL?headA:q->next;
        }
        return p;
    }
};
```




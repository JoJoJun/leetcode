# 环形链表

给定一个链表，判断链表中是否有环。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。

 

示例 1：

输入：head = [3,2,0,-4], pos = 1
输出：true
解释：链表中有一个环，其尾部连接到第二个节点。


示例 2：

输入：head = [1,2], pos = 0
输出：true
解释：链表中有一个环，其尾部连接到第一个节点。


示例 3：

输入：head = [1], pos = -1
输出：false
解释：链表中没有环。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/linked-list-cycle
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

# 分析

判断链表中是否有环，很经典的用快慢双指针

一个始终走两步，一个始终走一步。如果是环形的话，快指针总会追上慢指针，两者相遇（就像操场跑步一样）。不过相遇的地方未必是环的起点。 时间复杂度O(n)，空间复杂度O(1)



不过也同样可以记录下已经有的节点，判断是否重复了。选择合适的数据结构比如set，时间复杂度和空间复杂度都是O(1)

# 代码

## c++  

双指针

```cpp
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL)return false;
        ListNode * p = head;
        ListNode * fast = head->next;
        if(fast == NULL)return false;
        else if(fast == p)return true;
        fast = fast->next;
        while(fast != NULL){
            if(fast == p)
                return true;
            p = p->next;
            fast = fast->next;
            if(fast!=NULL)
                fast = fast->next;
        }
        return false;
    }
};
```

## python

集合判断

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        listset = set()
        while head:
            if head in listset:
                return True
            listset.add(head)
            head = head.next
        return False
```


# 环形链表 II

给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。

说明：不允许修改给定的链表。

 

> 示例 1：
>
> 输入：head = [3,2,0,-4], pos = 1
> 输出：tail connects to node index 1
> 解释：链表中有一个环，其尾部连接到第二个节点。
>
> 示例 2：
>
> 输入：head = [1,2], pos = 0
> 输出：tail connects to node index 0
> 解释：链表中有一个环，其尾部连接到第一个节点。
>
> 示例 3：
>
> 输入：head = [1], pos = -1
> 输出：no cycle
> 解释：链表中没有环。


进阶：
你是否可以不用额外空间解决此题？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/linked-list-cycle-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

# 分析

在141的基础上找环的入口。141的快慢指针相遇必是在环内，但未必是环的入口。

找到环内一点后，另一个节点从开头开始

题解说的比较明白：

![1591760387523](C:\Users\zzj\AppData\Roaming\Typora\typora-user-images\1591760387523.png)

代码如下:

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
    ListNode* iscicle(ListNode * head){
        if(head == NULL)return NULL;
        ListNode * p = head;
        ListNode * fast  = head;
        if(p->next == p)
        return p;
        while(fast != NULL && fast->next != NULL){
            p = p->next;
            fast = fast->next->next;
            if(p == fast)
            return p;
        }
        return NULL;
    }
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL)return NULL;
        ListNode * incicle = iscicle(head);
        if(incicle == NULL)return NULL;
        ListNode * s1 = head;
        ListNode * s2 = incicle;
        while(s1!=s2){
            s1 = s1->next;
            s2 = s2->next;
        }
        return s1;
    }
};
```



当然也可以用set，判断第一个重复的节点，就是入口了
# 回文链表

请判断一个链表是否为回文链表。

示例 1:

输入: 1->2
输出: false
示例 2:

输入: 1->2->2->1
输出: true
进阶：
你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindrome-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

# 分析

普通 的O(n)时间复杂度O(n)空间复杂度的方法，可以是转成数组后双指针，具体代码如下所示：

C++

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
    bool isPalindrome(ListNode* head) {
        if(head == NULL)
        return true;
        vector<int>linklist;
        ListNode*p = head;
        while(p!=NULL){
            linklist.push_back(p->val);
            p = p->next;
        }
        int i = 0,j = linklist.size()-1;
        while(i<j){
            if(linklist[i]!=linklist[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};
```



另一种方法不再使用额外的空间，而是首先用快慢指针找到链表中点，再反转后半部分链表，然后分别从头部和中间开始正向检查。

比较困难的点再中间的逆转链表，具体代码如下：

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
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL)
        return true;
       ListNode * fast = head, *slow = head, *prev = NULL;
        while(fast){
            slow = slow->next;
            fast = fast->next?fast->next->next:fast->next;
        }
        while(slow){
            ListNode * ovn = slow->next;
            slow->next = prev;
            prev = slow;
            slow = ovn;
        }
        while(head && prev){
            if(head->val != prev->val)
                return false;
            head = head->next;
            prev = prev->next;
        }
        return true;
    }
};
```


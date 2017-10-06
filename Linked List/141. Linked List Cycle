Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra spacep

题意：判断一个链表是否成环

思路：快慢两个指针的应用

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
    bool hasCycle(ListNode *head) {
        ListNode* q = head;
        ListNode* p = head;
        while(q != NULL && p != NULL && p->next != NULL)
        {
            q = q->next;//slow pointer
            p = p->next->next;//fast pointer
            if(q == p) return true;
        }
        return false;
    }
};

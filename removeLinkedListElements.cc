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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode top(0);
        top.next = head;
        // two pointers 36ms
        // ListNode *pre = &top, *cur = head; // can only use one pointer and judge p->next->val == val
        // while (cur) {
        //     if (cur->val == val) {
        //         pre->next = cur->next;
        //         delete cur;
        //         cur = pre->next;
        //     }else {
        //         cur = cur->next;
        //         pre = pre->next;
        //     }
        // }
        
        // use one pointer 32ms
        ListNode *p = &top;
        ListNode *temp = NULL;
        while (p->next) {
            if (p->next->val == val) {
                temp = p->next;
                p->next = p->next->next;
                delete temp;
            } else {
                p = p->next;
            }
        }
        return top.next; // not head (head can be deleted)
    }
};
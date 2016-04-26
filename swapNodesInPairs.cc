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
    ListNode* swapPairs(ListNode* head) {
        // recursive way
        // return swapTwo(head);
        
        // iterate way
        // if (!head || !head->next)
        //     return head;
        // ListNode fakeHead(0);  
        // fakeHead.next = head;
        // ListNode *pre = &fakeHead, *cur = head;
        // while (cur && cur->next) {
        //     ListNode *tmp = cur->next;
        //     pre->next = tmp;
        //     cur->next = tmp->next;
        //     tmp->next = cur;
            
        //     pre = cur;
        //     cur = cur->next;
        // }
        // return fakeHead.next;
        
        // clearer way
        ListNode **pp = &head, *a, *b;
        while ((a = *pp) && (b = a->next)) {
            a->next = b->next;
            b->next = a;
            *pp = b;
            pp = &(a->next);
        }
        return head;
    }
    
    ListNode* swapTwo(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode *tmp = head->next;
        head->next = swapTwo(tmp->next);
        tmp->next = head;
        return tmp;
    }
};
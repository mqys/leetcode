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
    ListNode* reverseList(ListNode* head) {
        /*
            iterative way
        */
        // if (head == NULL || head->next == NULL) return head;
        // ListNode *pre = head, *cur = head->next, *temp;
        // while (cur) {
        //     temp = cur->next;
        //     cur->next = pre;
        //     pre = cur;
        //     cur = temp;
        // }
        // head->next = NULL;
        // return pre;
        
        /*
            recursive way
        */
        // if (!head) return head;
        // ListNode* r;
        // while (r->next) 
        //     r = r->next;
        // reverse(head);
        // return r;
        if (head == NULL || head->next == NULL) return head;
        ListNode *temp = reverseList(head->next);
        head->next->next = head;  // 注意对比上面另一种递归的方法
        head->next = NULL;
        return temp;         
    }
    // ListNode* reverse(ListNode* head) {
    //     if (head->next == NULL) return head;
    //     ListNode *temp = reverse(head->next);
    //     temp->next = head;
    //     head->next = NULL;
    //     return head;        
    // }
};
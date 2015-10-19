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
    void deleteNode(ListNode* node) {
/*        // fake delete, move the val
        ListNode * n = node->next;
        while (n->next) {
            node->val = n->val;
            node = n;
            n = n->next;
        }
        node->val = n->val;
        node->next  = NULL;
        delete n;*/
        
        // copy the next one, then delete the next one
        ListNode* temp = node->next;
        node->val = temp->val;
        node->next = temp->next;
        delete temp;
    }
};
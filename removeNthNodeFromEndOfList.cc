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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /*
            use two pointers: left right
            the distance between the two pointers is n
            when right to the end , left points to the element to be removed
            for deleting, need another point llfet
        */
        // ListNode *left = head, *right = head, *lleft = left;
        // while (n--)
        //     right = right->next;

        // while (right) {
        //     lleft = left;
        //     left = left->next;
        //     right = right->next;
        // }
        // //whether delete the first node
        // if (head != left) { // not first
        //     lleft->next = left->next;
        // }
        // else { // first
        //     head =  left->next;
        // }
        // delete left;
        // return head;
        
        /*
        can only use two pointers when juding using right->next
        */
        ListNode nodeHead(0);  // add nodeHead to avoid considering whether left == head
        nodeHead.next = head;
        ListNode *left = &nodeHead, *right = &nodeHead;
        while (n--)
            right = right->next;
        while (right->next) {
            left = left->next;
            right = right->next;
        }
        delete left->next;
        left->next = left->next->next;
        return nodeHead.next;
    }
};
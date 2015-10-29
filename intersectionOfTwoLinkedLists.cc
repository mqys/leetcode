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
        ListNode *a = headA, *b = headB;
        int countA = 0, countB = 0;
        while (a != NULL) {a = a->next; ++countA;}
        while (b != NULL) {b = b->next; ++countB;}
        
        a = headA, b = headB;
        int dif = abs(countA - countB);
        if (countA > countB) 
            while (dif) {a = a->next; --dif;}
        else
            while (dif) {b = b->next; --dif;}
        
        while (a != b) {
            a = a->next;
            b = b->next;
        }
        return a;
    }
};
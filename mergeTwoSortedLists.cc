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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *newStart = new ListNode(0), *newEnd = newStart; // 增加头节点便于遍历
        ListNode *i = l1, *j = l2;
        while (i&&j) {
            ListNode *temp;
            if (i->val < j->val) {
                temp = i;
                i = i->next;
                newEnd->next = temp;
                newEnd = temp;
            }
            else {
                temp = j;
                j = j->next;
                newEnd->next = temp;
                newEnd = temp;
            }
        }
        if (i) 
            newEnd->next = i;
        else if (j) 
            newEnd->next = j;
        return newStart->next;
    }
};
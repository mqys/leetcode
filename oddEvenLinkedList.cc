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
    ListNode* oddEvenList(ListNode* head) {
        // --- 20 ms ---
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* oddend = head;
        ListNode* evenend = head->next;
        ListNode* cur = evenend->next;
        bool isOdd = true;
        while (cur) {
            if (isOdd) {
                ListNode* temp = cur->next;
                cur->next = oddend->next;
                oddend->next = cur;
                oddend = cur;
                evenend->next = temp;
                cur =  temp;
                isOdd = false;
            } else {
                evenend = cur;
                cur = cur->next;
                isOdd = true;
            }
        }
        return head;
    }
};
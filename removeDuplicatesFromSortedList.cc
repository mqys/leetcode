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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) return head;
        // int currentVal = head->val;
        ListNode* preTemp = head;
        ListNode* temp = head->next;
        // while (temp) {
        //     if (temp->val == currentVal) {
        //         preTemp->next = temp->next;
        //         delete temp;
        //         temp = preTemp->next;
        //     }
        //     else {
        //         currentVal = temp->val;
        //         preTemp = temp;
        //         temp = temp->next;
        //     }
        // }
        while (temp) {
            if (temp->val == preTemp->val) {
                preTemp->next = temp->next;
                delete temp;
                temp = preTemp->next;
            }
            else {
                preTemp = temp;
                temp = temp->next;
            }
        }
        return head;
        // 注释掉的代码20ms，现代码12ms
        // 没有必要的时候不需要引入额外的变量
    }
};
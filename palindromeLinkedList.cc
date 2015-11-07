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
    bool isPalindrome(ListNode* head) {
        // --- time out ---
        // one pointer left, two pointers on the right to reuse in next loop
        // if (head == NULL || head->next == NULL) return true;
        // ListNode *left = head, *right = head, *end = NULL;
        // while (right != end && left != end) { 
        //     while (right->next != end) right = right->next; // calcu new right
        //     if (left->val != right->val)
        //         return false;
        //     left = left->next;
        //     end = right;
        //     right = left->next;
        // }
        // return true;
        
        // use extra stack -- 28ms
        stack<int> s;
        int count = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            ++count;
            temp = temp->next;
        }
        int halfLen = count / 2;
        temp = head;
        for (int i = 0; i < halfLen; ++i) {
            s.push(temp->val);
            temp = temp->next;
        }
        if (count & 1)
            temp = temp->next;
        while (temp) {
            if (temp->val != s.top())
                return false;
            temp = temp->next;
            s.pop();
        }
        return true;
        
        // another way : 1. find the half pos
        //               2. reverse the second half
        //               3. compare the element
        //               4. restore the second half
        
        // another way to get the half, not count the num:
                    // two pointers: a slow one and a fast one
                    //     slow one takes one step each time
                    //     fast one takes two steps each time
        
    }
};
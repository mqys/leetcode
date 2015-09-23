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
    //slow way: get the num then form the sum
    // int getNum(ListNode* l){
    //     ListNode *temp = l;
    //     int num = 0;
    //     int i;
    //     for(i = 0; temp->next != NULL; ++i){
    //         num += i * 10 * temp->val; //个位遗漏！ 0*xxx
    //         temp = temp->next;
    //     }
    //     num += i * 10 * temp->val;
    //     num += l->val;
    //     return num;
    // }
    // ListNode* formList(int sum){
    //     //memory usage ??? 
    //     int val= 0 ,temp = sum;
    //     ListNode *r = NULL,*t = NULL,*h = NULL;
    //     while(temp != 0){
    //         val = temp % 10;
    //         temp = temp / 10;
    //         h = new ListNode(val);
    //         if(r == NULL){
    //             r = h;
    //             t = h;
    //         }
    //         if(t != NULL)
    //             t->next = h;
    //     }
    //     return r;
    // }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //out of time!
        // int sum = getNum(l1) + getNum(l2);
        // return formList(sum);
        
        //try direct sum up, return the longer list head
        //key is parallel addition
        //out of time!
        // ListNode *b1=l1, *b2=l2, *t1=l1, *t2=l2;
        // int carry = 0;
        // while((t1 != NULL) || (t2 != NULL))
        // {
            
        //     if((t1!=NULL)&&(t2!=NULL)){
        //         t1->val += t2->val + carry;
        //         if(t1->val > 10){
        //             t1->val = t1->val % 10;
        //             carry = 1;
        //         }
        //         else
        //             carry = 0;
        //         t2->val = t1->val;
        //         t1 = t1->next;
        //         t2 = t2->next;
        //     }
        //     else if((t1=NULL)&&(t2!=NULL)){
        //         t2->val += carry;
        //         if(t2->val > 10){
        //             t2->val = t2->val % 10;
        //             carry =1;
        //         }
        //         else
        //             carry = 0;
        //         t2 = t2->next;
        //         if(t2 == NULL)
        //             return b2;
        //     }
        //     else if((t1!=NULL)&&(t2=NULL)){
        //         t1->val += carry;
        //         if(t1->val > 10){
        //             t1->val = t1->val % 10;
        //             carry =1;
        //         }
        //         else
        //             carry = 0;
        //         t1 = t1->next;
        //         if(t1 == NULL)
        //             return b1;
        //     }
        // }
        // return b1;
        
        //dirty code, not clean!!!
        //have effect on l1l2
        //only change list1, when running out of node, borrow
        //parallel pointers -> how to write the code ??
        ListNode *b1=l1, *t1=l1, *t2=l2, *temp = NULL, *bt1 = t1; //bt1 behind t1 
        int carry = 0, sum = 0;
        while((t1 != NULL)||(t2 != NULL)){
            if(t1 == NULL){ //t2 NOT NULL
                sum = t2->val + carry;
                carry = sum / 10;
                sum = sum % 10;
                t2->val = sum;
                bt1->next = t2;
                bt1 = t2;
                t2 = t2->next;
            }
            else if(t2 == NULL){//t1 NOT NULL
                sum = t1->val + carry;
                carry = sum / 10;
                sum = sum % 10;
                t1->val = sum;
                bt1 = t1;
                t1 = t1->next;
            }
            else {//t1,t2 NOT NULL
                sum = t1->val + t2->val + carry;
                carry = sum / 10;
                sum = sum % 10;
                t1->val = sum;
                bt1 = t1;
                t1 = t1->next;
                t2 = t2->next;
            }
        }
        //attation: [5],[5] have a carry 1!
        if(carry != 0){
            bt1->next = new ListNode(carry);
        }
        return b1;
        
        //could try create a new list without breaking l1 l2
        //...
    }
    
};
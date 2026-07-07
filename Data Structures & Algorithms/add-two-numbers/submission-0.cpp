/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr && l2 == nullptr) return nullptr;
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        int carry = 0 ;

        ListNode* head = nullptr;
        ListNode* cur = nullptr;

        while(l1 or l2){
            int sum = carry + ((l1)?l1->val:0) + ((l2)?l2->val:0) ;
            carry = (sum > 9)?1:0;
            sum = sum%10 ;

            if(l1){
                l1 = l1->next;
            }
            if(l2){
                l2 = l2->next;
            }

            ListNode* temp = new ListNode(sum) ;
            if(head == nullptr){
                head = temp ;
                cur = temp;
            }else{
                cur->next = temp ;
                cur = temp;
            }

        }

        if(carry >= 1){
            ListNode* temp = new ListNode(carry) ;
            cur->next = temp ;
        }

        return head ;
    }
};

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
        ListNode* dummy = new ListNode(0);
        ListNode *temp = dummy;

        int carry = 0, sum = 0;

        while(l1 || l2){
            int sum = ((l1)?l1->val:0) + ((l2)?l2->val:0) + carry;
            carry = (sum > 9)?1:0;
            sum = sum%10;
            ListNode* curr = new ListNode(sum);
            temp->next = curr;
            temp = temp->next;

            if(l1)
                l1 = l1->next;
            if(l2)
                l2 = l2->next;
        }
        if(carry > 0){
            temp->next = new ListNode(carry);
        }
        return dummy->next;
    }
};

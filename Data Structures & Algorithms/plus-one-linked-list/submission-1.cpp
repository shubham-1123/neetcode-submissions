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
    // ListNode* plusOne(ListNode* head) {
    //     if(!head)return head;
    //     head = reverseLL(head);
    //     ListNode* ptr = head, *prev = nullptr;
    //     while(ptr && ptr->val == 9){
    //         prev = ptr;
    //         ptr->val = 0;
    //         ptr = ptr->next;
    //     }
    //     if(ptr == nullptr){
    //         prev->next = new ListNode(1);
    //         return reverseLL(head);
    //     }
    //     ptr->val = ptr->val +1;
    //     return reverseLL(head);
    // }
    ListNode* plusOne(ListNode* head){
        if(!head)return head;
        head = reverseLL(head);
        int carry = 1;
        ListNode* curr = head, *prev = nullptr;
        while(curr){
            int sum = (curr->val) + carry;
            carry = (sum>9)?1:0;
            sum = sum%10;
            curr->val = sum;
            prev = curr;
            curr = curr->next;
        }
        if(carry){
            ListNode* temp = new ListNode(carry);
            prev->next = temp;
        }
        head = reverseLL(head);
        return head;
    }
    ListNode* reverseLL(ListNode* head){
        if(!head || !head->next)return head;
        ListNode* curr = head, *prev = nullptr;
        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};

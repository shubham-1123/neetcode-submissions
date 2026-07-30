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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next || k == 1) return head;
        int n = 0;
        ListNode* ptr = head;
        while(ptr){
            n ++ ;
            ptr = ptr->next;
        }
        if(n < k) return head;

        ListNode* curr = head, *prev = nullptr;
        n = 0;
        while(curr && n<k){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next ;
            n ++;
        }
        if(curr){
            head->next = reverseKGroup(curr, k);
        }
        return prev;
    }
};

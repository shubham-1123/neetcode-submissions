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
        if(!head || !head->next || k==1)return head;
        auto check_len = [](ListNode* h1){
            int n = 0;
            while(h1){
                n ++;
                h1 = h1->next;
            }
            return n;
        };
        int n = check_len(head);
        if(n < k) return head;

        ListNode* curr = head, *prev = nullptr;
        int i = 0;
        while(curr && i < k){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr ;
            curr = next;
            i ++;
        }
        if(curr){
            head->next = reverseKGroup(curr, k);
        }
        return prev;
    }
};

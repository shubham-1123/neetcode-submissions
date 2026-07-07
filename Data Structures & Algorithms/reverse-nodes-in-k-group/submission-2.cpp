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
    int findLen(ListNode* ptr){
        int n = 0;
        while(ptr){
            n ++;
            ptr = ptr->next;
        }
        return n;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr or head->next == nullptr or k == 1) return head;
        int len = findLen(head);
        if(len < k) return head; 

        ListNode* curr = head, *prev = nullptr; 
        int i = 0;
        while(i < k && curr){
            ListNode* next = curr->next ;
            curr->next = prev;
            prev = curr;
            curr = next; 
            i ++;
        }

        if(curr){
            head->next = reverseKGroup(curr, k);
        }
        return prev;
    }
};

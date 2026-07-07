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
        if(head == nullptr or head->next == nullptr or k == 1) return head;
        ListNode* ptr = head ;
        int n = 0;
        while(ptr){
            ptr = ptr->next;
            n ++;
        }
        if(n < k) return head;

        ListNode* cur = head ;
        ListNode* prev = nullptr;

        int count = 0;
        while(cur && count!=k){
            ListNode* next = cur->next ;
            cur->next = prev ;
            prev = cur;
            cur = next ;
            count ++ ;
        }
        if(cur!=nullptr){
            head->next = reverseKGroup(cur, k);
        }

        return prev;

    }
};

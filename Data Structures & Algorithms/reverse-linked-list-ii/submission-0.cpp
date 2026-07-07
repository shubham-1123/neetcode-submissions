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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right)return head;

        ListNode* curr = head, *prev = nullptr;
        int i=0;

        while(i < left-1 && curr){
            prev = curr;
            curr = curr->next;
            i ++ ;
        }
        
        ListNode* temp = nullptr;
        while(i < right && curr){
            ListNode* next = curr->next;
            curr->next = temp;
            temp = curr;
            curr = next;
            i ++ ;
        }
        if(prev != nullptr){
            prev->next->next = curr;
            prev->next = temp;
            return head;
        }
        head->next = curr;
        return temp;
    }
};
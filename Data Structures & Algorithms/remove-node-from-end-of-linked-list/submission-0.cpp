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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int len = 0 ;
        ListNode* p= head ;
        while(p){
            p = p->next;
            len ++;
        }

        if(n == len){
            ListNode* tmp = head;
            head = head->next ;
            delete tmp;
            return head;
        }

        int i = 0;
        p = head;
        ListNode* prev = nullptr;
        while(i < (len-n)){
            prev = p;
            p = p->next ;
            i ++ ;
        }

        prev->next = p->next ;
        return head;
        // if(p->next == nullptr){
        //     prev->next = nullptr ;
        //     delete p;
        //     return head;
        // }


    }
};

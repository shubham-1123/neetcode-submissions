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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return nullptr ;
        if(lists.size() == 1) return lists[0] ;

        ListNode* l1 = lists[0] ;
        ListNode* l2 = lists[1] ;

        ListNode* head = merge(l1, l2) ;

        for(int i=2;i<lists.size();i++){
            head = merge(head, lists[i]) ;
        }
        return head;
    }
    ListNode* merge(ListNode* head1, ListNode* head2){
        if(head1 == nullptr && head2 == nullptr)return nullptr ;
        if(head1 == nullptr) return head2;
        if(head2 == nullptr) return head1;

        ListNode* temp = nullptr;
        ListNode* cur  = nullptr;

        if(head1->val <= head2->val){
            temp = head1;
            cur = head1;
            head1 = head1->next;
        }else{
            temp = head2;
            cur = head2; 
            head2 = head2->next;
        }

        while(head1 && head2){
            if(head1->val <= head2->val){
                temp->next = head1;
                temp = head1;
                head1 = head1->next ;
            }else{
                temp->next = head2;
                temp = head2;
                head2 = head2->next;
            }
        }

        if(head1)
            temp->next = head1;
        if(head2)
            temp->next = head2;
        return cur;
    }
};

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
    struct comp{
        bool operator() (ListNode* first, ListNode* second){
            return (first->val > second->val);
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,  vector<ListNode*>, comp> pq;
        
        for(auto ptr : lists){
            if(ptr){
                pq.push(ptr);
            }
        }

        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        while(!pq.empty()){
            ListNode* curr = pq.top();
            pq.pop();
            temp->next = curr;
            temp = temp->next;
            if(curr->next){
                pq.push(curr->next);
            }
        }
        return dummy->next;
    }
};

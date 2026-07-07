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

struct Comp{
    bool operator()(ListNode* a, ListNode* b){
        return (a->val > b->val);
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        priority_queue<ListNode*, vector<ListNode*>, Comp> pq;
        for(auto &ptr : lists){
            if(ptr){
                pq.push(ptr);
            }
        }

        while(!pq.empty()){
            ListNode* curr = pq.top();
            pq.pop();
            temp->next = curr;
            temp = temp->next;
            if(curr->next)
                pq.push(curr->next);
        }
        return dummy->next;
    }
};

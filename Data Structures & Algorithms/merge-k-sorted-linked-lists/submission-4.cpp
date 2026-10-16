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
        priority_queue<ListNode*, vector<ListNode*>, Comp>pq; // min priority queue

        for(auto &x: lists){
            if(x)
                pq.push(x);
        }
        ListNode* head = new ListNode(0);
        ListNode* temp = head;

        while(!pq.empty()){
            ListNode* src = pq.top();
            pq.pop();
            temp->next = src;
            temp = temp->next;
            if(src && src->next){
                pq.push(src->next);
            }
        }
        return head->next;
    }
};

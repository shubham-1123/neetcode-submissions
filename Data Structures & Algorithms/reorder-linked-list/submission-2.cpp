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
    void reorderList(ListNode* head) {
        stack<ListNode*> st;
        int n = 0;
        ListNode* ptr = head ;
        while(ptr){
            n ++ ;
            st.push(ptr);
            ptr = ptr->next;
        }
        ListNode* curr = head, *prev = nullptr;
        int i = 0;

        while(i < n/2 && curr){
            prev = curr->next;
            curr->next = st.top();
            curr = curr->next;
            curr->next = prev;
            curr = curr->next;
            st.pop();
            i ++;
        }
        curr->next = nullptr;
        return ;
    }
};

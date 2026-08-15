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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<ListNode*> st1, st2;
        stack<int> st3;
        ListNode* ptr = l1;
        while(ptr){
            st1.push(ptr);
            ptr = ptr->next;
        }
        ptr = l2;
        while(ptr){
            st2.push(ptr);
            ptr = ptr->next;
        }
        int carry = 0;
        while(!st1.empty() && !st2.empty()){
            int val = st1.top()->val + st2.top()->val + carry;
            st1.pop();
            st2.pop();
            carry = (val > 9)?1:0;
            val = val%10;
            st3.push(val);
        }
        while(!st1.empty()){
           int val = st1.top()->val + carry;
           st1.pop();
           carry = (val>9)?1:0;
           val = val%10;
           st3.push(val); 
        }
        while(!st2.empty()){
           int val = st2.top()->val + carry;
           st2.pop();
           carry = (val>9)?1:0;
           val = val%10;
           st3.push(val); 
        }

        if(carry)
            st3.push(carry);

        ListNode* head = new ListNode(0);
        ListNode *temp = head;

        while(!st3.empty()){
            int val = st3.top();
            // std::cout << val << " ";
            st3.pop();
            ListNode* curr = new ListNode(val);
            temp->next = curr;
            temp = temp->next;
        }
        return head->next;
    }
};
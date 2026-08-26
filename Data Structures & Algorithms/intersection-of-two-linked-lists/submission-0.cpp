/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* ptr1 = headA, *ptr2 = headB;
        int d1 = 0, d2 = 0;
        while(ptr1){
            ptr1 = ptr1->next;
            d1 ++;
        }
        while(ptr2){
            d2 ++;
            ptr2 = ptr2->next;
        }
        ptr1 = headA, ptr2 = headB;
        if(d2 > d1)
            swap(ptr1, ptr2);
        
        d1 = abs(d1-d2);

        while(d1!=0){
            d1 --;
            ptr1 = ptr1->next;
        }

        while(ptr1 && ptr2 && (ptr1 != ptr2)){
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return (ptr1 == ptr2)?ptr1:nullptr;
    }
};
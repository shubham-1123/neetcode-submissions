/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<int, Node*> mp1 ; //storing new ll data
        unordered_map<Node*, int> mp2 ; //storing old ll data
        Node* tmp = head;

        int id = 0;
        Node* new_head = nullptr ;
        Node* cur = nullptr ;

        while(head){
            if(new_head == nullptr){
                Node* temp = new Node(head->val);
                new_head = cur = temp ;
                mp1[id] = temp ;
            }else{
                Node* temp = new Node(head->val) ;
                cur->next = temp;
                cur = temp ;
                mp1[id] = temp ;
            }
            mp2[head] = id;
            head = head->next;
            id ++ ;
        }

        head = tmp ;

        while(head){
            int index = mp2[head] ;
            Node* cur = mp1[index];
            if(head->random == nullptr){
                cur->random = nullptr ;
            }else{
                int idx = mp2[head->random];
                cur->random = mp1[idx];
            }
            head = head->next ;
        }

        return new_head;

    }
};

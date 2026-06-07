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
        Node* temp = head;
        unordered_map<Node*, Node*> copyWalaMap;

        while(temp!=nullptr){
            copyWalaMap[temp] = new Node(temp->val);
            temp = temp->next;
        }

        temp = head;
        Node* newHead = copyWalaMap[temp];
        while(temp!=nullptr){
            copyWalaMap[temp]->next = copyWalaMap[temp->next];
            copyWalaMap[temp]->random = copyWalaMap[temp->random];

            temp = temp->next;
        }

        return newHead;
    }
};

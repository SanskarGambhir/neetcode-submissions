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
        ListNode* temp = head;
        unordered_map<int, ListNode*> indices;
        int i=0;
        int count = 0;

        while(temp != nullptr){
            indices[i] = temp;

            i++;
            count++;
            temp = temp->next;
        }

        temp = indices[0];
        for(int i=0; i<count/2; i++){
            temp->next = indices[count-i-1];
            temp = temp->next;

            temp->next = indices[i+1];
            temp = temp->next;
        }
        temp->next = nullptr;
    }
};

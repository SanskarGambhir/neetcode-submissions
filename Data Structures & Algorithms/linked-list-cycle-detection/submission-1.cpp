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
    bool hasCycle(ListNode* head) {
        ListNode* temp = head;
        unordered_map<ListNode*, int> address;

        while(temp != nullptr){
            if(address.find(temp) != address.end()){
                return true;
            }

            address[temp] = 1;
            temp = temp->next;
        }

        return false;
    }
};

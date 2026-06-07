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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL){
            return NULL;
        } 
        else if(head->next == nullptr){
            return head;
        }
        else if(head->next->next == nullptr){
            ListNode* prev = head;
            ListNode* current = head->next;

            current->next = prev;
            prev->next = nullptr;
            head = current;
            return head;
        }
        else{
            ListNode* prev = head;
            ListNode* current = head->next;

            while(current != nullptr){
                ListNode* currentKaNext = current->next;
                current->next = prev;
                prev = current;
                current = currentKaNext;
            }
            head->next = nullptr;
            head = prev;
            return head;
        }
        
        return head;
    }
};

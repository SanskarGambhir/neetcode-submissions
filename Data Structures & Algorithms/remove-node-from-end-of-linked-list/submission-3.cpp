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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int listLength = 0;

        while(temp!=nullptr){
            listLength++;
            temp = temp->next;
        }

        temp = head;
        if(listLength-n==0 && temp==head){
            head = head->next;
            delete temp;

            return head;
        }

        int count = 0;
        while(temp!=nullptr){
            count++;
            if(count==listLength-n){
                ListNode* nodeToDelete = temp->next;
                temp->next = temp->next->next;
                delete nodeToDelete;

                return head;
            }
            else{
                temp = temp->next;
            }
        }

        return head;
    }
};

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* newListHead = new ListNode();
        ListNode* newListMover = newListHead;

        while(temp1!=nullptr && temp2!=nullptr){
            if(temp1->val < temp2->val){
                ListNode* newListTemp = new ListNode(temp1->val);
                newListMover->next = newListTemp;
                newListMover = newListTemp;
                temp1 = temp1->next;
            }
            else{
                ListNode* newListTemp = new ListNode(temp2->val);
                newListMover->next = newListTemp;
                newListMover = newListTemp;
                temp2 = temp2->next;
            }
        }

        while(temp1 != nullptr){
            ListNode* newListTemp = new ListNode(temp1->val);
            newListMover->next = newListTemp;
            newListMover = newListTemp;
            temp1 = temp1->next;
        }
        while(temp2 != nullptr){
            ListNode* newListTemp = new ListNode(temp2->val);
            newListMover->next = newListTemp;
            newListMover = newListTemp;
            temp2 = temp2->next;
        }

        newListHead = newListHead->next;
        return newListHead;       
    }
};

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
    ListNode* reverseList(ListNode* head) 
    {
        ListNode* prevptr=NULL;
        ListNode* currentptr=head;
        ListNode* nextptr;
        
        while(currentptr!=NULL){
            nextptr=currentptr->next;
            currentptr->next=prevptr;
                
            prevptr=currentptr;
            currentptr=nextptr;
        }
        return prevptr;
    }
};
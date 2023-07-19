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
    ListNode* reverseLL(ListNode**head){
        ListNode* prevptr=NULL;
        ListNode* currentptr=*head;
        ListNode* nextptr;
        
        while(currentptr!=NULL){
            nextptr=currentptr->next;
            currentptr->next=prevptr;
                
            prevptr=currentptr;
            currentptr=nextptr;
        }
        return prevptr;
    }
    bool isPalindrome(ListNode* head) {
        if(head==nullptr || head->next==nullptr)
            return true;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=reverseLL(&slow->next);
        slow=slow->next;
        while(slow!=NULL){
            if(head->val!=slow->val)
                return false;
            head=head->next;
            slow=slow->next;
        }
        return true;
    }
};
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
    void reverseLL(ListNode**head){
        ListNode* currptr=*head;
        ListNode* prevptr=NULL;
        ListNode* nextptr;
        
        while(currptr){
            nextptr=currptr->next;
            currptr->next=prevptr;
            
            prevptr=currptr;
            currptr=nextptr;
        }
        *head=prevptr;
    }
    
    int pairSum(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        slow=slow->next;
        reverseLL(&slow);
        int maxi=0;
        while(slow){
            maxi=max(maxi,((head->val)+(slow->val)));
            slow=slow->next;
            head=head->next;
        }
        return maxi;
	}
};
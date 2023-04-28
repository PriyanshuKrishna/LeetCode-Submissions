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
    ListNode* reverseLL(ListNode* lst){
        ListNode* currptr=lst;
        ListNode* prevptr=NULL;
        ListNode* nextptr=NULL;
        
        while(currptr!=NULL){
            nextptr=currptr->next;
            currptr->next=prevptr;
            
            prevptr=currptr;
            currptr=nextptr;
        }
        return prevptr;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode(0);
        ListNode* curr=dummy;
        l1=reverseLL(l1);
        l2=reverseLL(l2);
        int carry=0;
        while(l1!=NULL || l2!=NULL || carry==1){
            int sum=0;
            if(l1!=NULL){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;
            carry=sum/10;
            ListNode* node=new ListNode(sum%10);
            curr->next=node;
            curr=curr->next;
        }
        l1=reverseLL(l1);
        l2=reverseLL(l2);
        ListNode* res=reverseLL(dummy->next);
        return res;
    }
};
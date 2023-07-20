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
    ListNode* reverseLL(ListNode* head){
        ListNode* prevptr=NULL;
        ListNode* curptr=head;
        ListNode* nextptr;
        
        while(curptr){
            nextptr=curptr->next;
            curptr->next=prevptr;
            
            prevptr=curptr;
            curptr=nextptr;
        }
        return prevptr;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode();
        ListNode* cur=dummy;
        l1=reverseLL(l1);
        l2=reverseLL(l2);
        int carry=0;
        while(l1 || l2 || carry){
            int sum=0;
            if(l1){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2){
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;
            carry=sum/10;
            ListNode* node=new ListNode(sum%10);
            cur->next=node;
            cur=cur->next;
        }
        ListNode* res=reverseLL(dummy->next);
        return res;
    }
};

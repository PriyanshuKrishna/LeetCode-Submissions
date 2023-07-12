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
    ListNode* partition(ListNode* head, int x) {
        ListNode* left=new ListNode(0);
        ListNode* right=new ListNode(0);
        
        ListNode* lefttrail=left;
        ListNode* righttrail=right;
        
        while(head!=NULL){
            if(head->val<x){
                lefttrail->next=head;
                lefttrail=lefttrail->next;
            }
            else{
                righttrail->next=head;
                righttrail=righttrail->next;
            }
            head=head->next;
        }
        lefttrail->next=right->next;
        righttrail->next=NULL;
        
        return left->next;
    }
};

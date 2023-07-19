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
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* r_head=NULL;
        ListNode* ptr=head;
        
        while(ptr!=NULL){
            ListNode* tmp=new ListNode(ptr->val);
            tmp->next=r_head;
            r_head=tmp;
            ptr=ptr->next;
        }
        
        while(head && r_head){
            if(head->val!=r_head->val)  return false;
            
            head=head->next;
            r_head=r_head->next;
        }
        return true;
    }
};

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* cur=dummy;
        int dup;
        while(cur->next && cur->next->next){
            if(cur->next->val == cur->next->next->val){
                dup=cur->next->val;
                while(cur->next && cur->next->val==dup){
                    cur->next=cur->next->next;
                }
            }
            else{
                cur=cur->next;
            }
        }
        return dummy->next;
    }
};

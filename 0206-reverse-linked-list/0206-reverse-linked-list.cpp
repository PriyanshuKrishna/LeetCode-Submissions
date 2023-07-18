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
    ListNode* reverseList(ListNode* head) {
        ListNode* prevptr=NULL;
        return reverse(head,prevptr);
    }
    ListNode* reverse(ListNode* curptr,ListNode* prevptr){
        if(!curptr)  return prevptr;
        ListNode* nextptr=curptr->next;
        curptr->next=prevptr;
        return reverse(nextptr,curptr);
    }
};
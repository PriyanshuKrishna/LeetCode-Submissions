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
    void reorderList(ListNode* head) { 
        vector<int> tmp;
        ListNode* h=head;
        while(h){
            tmp.push_back(h->val);
            h=h->next;
        }
        h=head;
        int n=tmp.size();
        int j=n-1,i=0;
        
        while(h){
            if(i==j){
                h->val=tmp[i];
                break;
            }
            h->val=tmp[i];
            h=h->next;
            h->val=tmp[j];
            h=h->next;
            i++;j--;
        }
    }
};

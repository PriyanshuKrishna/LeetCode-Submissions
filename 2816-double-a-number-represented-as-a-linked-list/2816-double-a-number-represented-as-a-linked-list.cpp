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
    ListNode* doubleIt(ListNode* head) {
        vector<int> res;
        ListNode* dummy=head;
        while(dummy){
            res.push_back(dummy->val);
            dummy=dummy->next;
        }
        int n=res.size(),di=0;
        int carry=0,prevcarry=0;
        for(int i=n-1;i>=0;i--){
            int t=res[i]*2;
            prevcarry=carry;
            if(t>9)
                carry=t/10;
            else
                carry=0;
            di=t%10;
            res[i]=di+prevcarry;
        }
        if(carry){
            res.insert(res.begin(),carry);
        }
        ListNode* h=new ListNode(0);
        ListNode* hh=h;
        for(int i=0;i<res.size();i++){
            ListNode* tmp=new ListNode(res[i]);
            h->next=tmp;
            h=h->next;
        }
        return hh->next;
    }
};
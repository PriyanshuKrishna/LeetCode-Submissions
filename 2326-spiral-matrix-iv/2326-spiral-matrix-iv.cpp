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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> res(m,vector<int>(n,-1));
        int top=0,bottom=0,left=m-1,right=n-1;
        while(head!=NULL){
            for(int j=bottom;j<=right && head!=NULL;j++){
                res[top][j]=head->val;
                head=head->next;
            }
            top++;
            for(int i=top;i<=left && head!=NULL;i++){
                res[i][right]=head->val;
                head=head->next;
            }
            right--;
            for(int j=right;j>=bottom && head!=NULL;j--){
                res[left][j]=head->val;
                head=head->next;
            }
            left--;
            for(int i=left;i>=top && head!=NULL;i--){
                res[i][bottom]=head->val;
                head=head->next;
            }
            bottom++;
        }
        return res;
    }
};

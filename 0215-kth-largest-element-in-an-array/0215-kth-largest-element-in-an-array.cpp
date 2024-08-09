class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int ans=0;
        priority_queue<int> pq;
        for(auto it:nums){
            pq.push(it);
        }
        int res=0;
        while(!pq.empty() && k>0){
            res=pq.top();pq.pop();
            k--;
        }
        return res;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> mp;
        priority_queue<pair<int,int>> pq;
        for(auto it:nums){
            mp[it]++;
        }
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        while(!pq.empty() && k>0){
            auto it=pq.top();pq.pop();
            ans.push_back(it.second);
            k--;
        }
        return ans;
    }
};
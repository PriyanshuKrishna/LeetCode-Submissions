class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        for(auto it:words) 
            mp[it]++;
        priority_queue<pair<int,string>> pq;
        vector<string> vec;
        for(auto it:mp)  
            pq.push({-it.second,it.first});
        while(pq.size()!=k) 
            pq.pop();
        while(!pq.empty()){
            vec.push_back(pq.top().second);
            pq.pop();
        }
        reverse(vec.begin(),vec.end());
        return vec;
    }
};
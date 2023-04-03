class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto it:nums){
            mp[it]++;
        }
        vector<int> res;
        for(auto it:nums){
            if(mp.count(it-1) ||  mp.count(it+1) || mp[it]>1)
                continue;
            else
                res.push_back(it);
        }
        return res;
    }
};
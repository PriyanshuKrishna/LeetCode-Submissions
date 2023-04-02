class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> res;
        unordered_map<int,int> mp;
        for(auto it:nums)
            mp[it]++;
        while(mp.size()){
            vector<int> temp;
            for(auto it:mp)
                temp.push_back(it.first);
            for(auto it:temp)
                if(!(--mp[it]))
                    mp.erase(it);
            res.push_back(temp);
        }
        return res;
    }
};

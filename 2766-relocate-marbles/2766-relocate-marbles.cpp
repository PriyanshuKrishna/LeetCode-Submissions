class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(int i=0;i<moveFrom.size();i++){
            int from=moveFrom[i];
            int too=moveTo[i];
            
            if(mp.count(from)){
                int mar=mp[from];
                mp.erase(from);
                mp[too]=mar;
            }
        }
        vector<int> ans;
        for(auto it:mp){
            ans.push_back(it.first);
        }
        return ans;
    }
};

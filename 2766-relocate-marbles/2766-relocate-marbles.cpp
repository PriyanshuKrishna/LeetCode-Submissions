class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=1;
        }
        for(int i=0;i<moveFrom.size();i++){
            int x=mp[moveFrom[i]];
            mp[moveFrom[i]]=0;
            mp[moveTo[i]]+=x;
        }
        vector<int> ans;
        for(auto i:mp){
            if(i.second!=0) 
                ans.push_back(i.first);
        }
        return ans;
    }
};

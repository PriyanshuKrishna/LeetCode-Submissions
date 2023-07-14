class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        unordered_map<int,int> mp;
        int res=0;
        for(auto it:arr){
            mp[it]=mp[it-diff]+1;
            res=max(res,mp[it]);
        }
        return res;
    }
};

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long res=0;
        int maxival=0,maxdiff=0;
        for(auto it:nums){
            res=max(res,1LL*it*maxdiff);
            
            maxdiff=max(maxdiff,maxival-it);
            
            maxival=max(maxival,it);
        }
        return res;
    }
};

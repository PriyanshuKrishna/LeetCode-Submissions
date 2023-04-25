class Solution {
private:
    int robbed(int i,vector<int>& nums,vector<int>& dp){
        if(i==0)    return nums[i];
        if(i<0)     return 0;
        if(dp[i]!=-1)   return dp[i];
        int l=nums[i]+robbed(i-2,nums,dp);
        int r=robbed(i-1,nums,dp);
        return dp[i]=max(l,r);
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return robbed(n-1,nums,dp);
    }
};
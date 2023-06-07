class Solution {
public:
    int solve(vector<int>& nums,int ind,int sum,int target,vector<vector<int>>& dp){
        if(ind<0){
            if(sum==target) return 1;
            else return 0;
        }
        if(dp[ind][sum+1000]!=-1)  return dp[ind][sum+1000];
        int p=solve(nums,ind-1,sum+nums[ind],target,dp);
        int n=solve(nums,ind-1,sum-nums[ind],target,dp);
        return dp[ind][sum+1000]=(p+n);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size(),sum=0;
        for(auto it:nums) sum+=it;
        vector<vector<int>> dp(n,vector<int>(sum+1+1000,-1));
        return solve(nums,n-1,0,target,dp);
    }
};
class Solution {
public:
    int solve(vector<int>& nums,int ind,int target,vector<vector<int>>& dp){
        if(target==0) return 0;
        if(target<0 || ind>=nums.size()) return -1e5;
        if(dp[ind][target]!=-1) return dp[ind][target];
        
        int pick=1+solve(nums,ind+1,target-nums[ind],dp);
        int notpick=solve(nums,ind+1,target,dp);
        
        return dp[ind][target]=max(pick,notpick);
    }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        vector<vector<int>> dp(1001,vector<int>(1001,-1));
        int res=solve(nums,0,target,dp);
        return (res>0)?res:-1;
    }
};
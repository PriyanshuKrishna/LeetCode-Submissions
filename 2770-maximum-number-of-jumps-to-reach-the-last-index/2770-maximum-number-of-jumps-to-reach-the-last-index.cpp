class Solution {
public:
    int solve(int ind,vector<int>& nums,int tar,vector<int>& dp){
        if(ind==nums.size()-1)  return 0;
        
        if(dp[ind]!=-1)  return dp[ind];
        
        int ans=INT_MIN;
        for(int i=ind+1;i<nums.size();i++){
            if(abs(nums[i]-nums[ind])<=tar)
                ans=max(ans,1+solve(i,nums,tar,dp));
        }
        return dp[ind]=ans;
    }
    int maximumJumps(vector<int>& nums, int target) {
        vector<int> dp(nums.size(),-1);
        int ans=solve(0,nums,target,dp);
        return (ans>0)?ans:-1;
    }
};
class Solution {
public:
    int solve(int ind,int n,vector<int>& nums,vector<int>& dp){
        if(ind>=n) return 0;
        if(dp[ind]!=-1)  return dp[ind];
        int curval=nums[ind];
        int cursum=nums[ind];
        int index=ind+1;
        while(index<n && nums[index]==curval){
            cursum+=nums[ind];
            index++;
        }
        while(index<n && nums[index]==curval+1)
            index++;
        int take=cursum+solve(index,n,nums,dp);
        int notake=solve(ind+1,n,nums,dp);
        return dp[ind]=max(notake,take);
    }
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> dp(n+1,-1);
        return solve(0,n,nums,dp);
    }
};
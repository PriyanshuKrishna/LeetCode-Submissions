class Solution {
public:
    int solve(int ind,vector<int>& coins,int tar,vector<vector<int>>& dp){
        if(tar==0)
            return 1;
        if(ind==0){
            if(tar%coins[0]==0)  return 1;
            else return 0;
        }
        if(dp[ind][tar]!=-1)  return dp[ind][tar];
        int notake=solve(ind-1,coins,tar,dp);
        int take=0;
        if(coins[ind]<=tar )
            take=solve(ind,coins,tar-coins[ind],dp);
        return dp[ind][tar]=take+notake;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return solve(n-1,coins,amount,dp);
    }
}; 
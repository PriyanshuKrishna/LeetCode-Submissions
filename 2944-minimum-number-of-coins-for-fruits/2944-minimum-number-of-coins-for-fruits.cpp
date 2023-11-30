class Solution {
public:
    int solve(int ind,int n,vector<int>& prices,vector<int>& dp){
        if(ind>=n) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int res=1e9;
        for(int i=ind+1;i<=min(n,2*(ind+1));i++){
            res=min(res,solve(i,n,prices,dp));
        }
        return dp[ind]=prices[ind]+res;
    }
    int minimumCoins(vector<int>& prices) {
        vector<int> dp(prices.size(),-1);
        return solve(0,prices.size(),prices,dp);
    }
};
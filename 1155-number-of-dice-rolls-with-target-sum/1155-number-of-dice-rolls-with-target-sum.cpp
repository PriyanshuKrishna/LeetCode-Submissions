class Solution {
public:
    int mod=(int)1e9+7;
    int solve(int n,int tar,int k,vector<vector<int>>& dp){
        if(n==0 && tar==0) return 1;
        if(n<=0 || tar<=0) return 0;
        
        if(dp[n][tar]!=-1)  return dp[n][tar];
        
        int sum=0;
        for(int i=1;i<=k;i++){
            sum=(sum+solve(n-1,tar-i,k,dp)%mod)%mod;
        }
        return dp[n][tar]=sum;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+30,vector<int>(target+1000,-1));
        return solve(n,target,k,dp);
    }
};
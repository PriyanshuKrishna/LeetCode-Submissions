class Solution {
public:
    int mod=(int)1e9+7;
    long long solve(int n,int goal,int k,vector<vector<long long>>& dp){
        if(goal==0 && n==0)
            return 1;
        if(goal<0 || n<0)
            return 0;
        if(dp[goal][n]!=-1)
            return dp[goal][n];
        long long nsong=(solve(n-1,goal-1,k,dp)*n)%mod;
        long long rsong=0;
        if(n>k)
            rsong=(solve(n,goal-1,k,dp)*(n-k))%mod;
        return dp[goal][n]=(nsong+rsong)%mod;
    }
    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<long long>> dp(goal+1,vector<long long> (n+1,-1));
        return solve(n,goal,k,dp);
    }
};

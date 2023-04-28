class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1);
        for(int i=2;i<=n;i++){
            int jone=dp[i-1]+cost[i-1];
            int jtwo=dp[i-2]+cost[i-2];
            dp[i]=min(jone,jtwo);
        }
        return dp[n];
    }
};

class Solution {
public:
    long long solve(vector<vector<int>>& questions,int i,vector<long long>& dp){
        if(i>=questions.size()) return 0;
        if(dp[i])  return dp[i];
        int points=questions[i][0],jump=questions[i][1];
        long long pick=points+solve(questions,i+jump+1,dp);
        long long notpick=solve(questions,i+1,dp);
        return dp[i]=max(pick,notpick);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size(),0);
        return solve(questions,0,dp);
    }
};
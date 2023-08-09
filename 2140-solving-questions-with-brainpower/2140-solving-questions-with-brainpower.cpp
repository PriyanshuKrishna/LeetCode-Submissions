class Solution {
public:
    long long solve(vector<vector<int>>& question,int ind,vector<long long>& dp){
        if(ind>=question.size()) return 0;
        if(dp[ind]) return dp[ind];
        int points=question[ind][0],jump=question[ind][1];
        long long notake=points+solve(question,ind+jump+1,dp);
        long long take=solve(question,ind+1,dp);
        return dp[ind]=max(take,notake);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size(),0);
        return solve(questions,0,dp);
    }
};
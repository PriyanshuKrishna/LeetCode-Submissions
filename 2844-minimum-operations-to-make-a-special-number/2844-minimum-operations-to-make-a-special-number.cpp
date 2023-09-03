class Solution {
public:
    int solve(int ind,int num,string& nums,vector<vector<int>>& dp){
        if(ind==nums.length()){
            if(num%25==0) 
                return 0;
            else
                return 1e9;
        }
        
        if(dp[ind][num]!=-1) return dp[ind][num];
        
        int digit=nums[ind]-'0';
        int notpick=1+solve(ind+1,num,nums,dp);
        int pick=0+solve(ind+1,((num*10+digit)%25),nums,dp);
        return dp[ind][num]=min(pick,notpick);
    }
    int minimumOperations(string nums) {
        int n=nums.length();
        vector<vector<int>> dp(n+1,vector<int>(25,-1));
        return solve(0,0,nums,dp);
    }
};

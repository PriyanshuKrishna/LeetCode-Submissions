class Solution {
public:
    int solve(vector<int>& v){
        vector<int> dp(v.size(),0);
        dp[0]=v[0];
        dp[1]=max(v[0],v[1]);
        for(int i=2;i<v.size();i++){
            dp[i]=max(dp[i-1],v[i]+dp[i-2]);
        }
        return dp[v.size()-1];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        
        vector<int> v1(nums.begin(),nums.end()-1);
        vector<int> v2(nums.begin()+1,nums.end());
        
        return max(solve(v1),solve(v2));
    }
};

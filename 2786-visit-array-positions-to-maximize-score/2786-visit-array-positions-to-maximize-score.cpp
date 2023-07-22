class Solution {
public:
    long long maxScore(vector<int>& nums, int x) {
        int n=nums.size();
        long long ans=0;
        vector<long long> dp={0,0};
        for(int i=n-1;i>=0;i--){
            int tmp=nums[i]%2;
            long long t=dp[tmp]+nums[i];
            long long nt=dp[1-tmp]-x+nums[i];
            ans=max(t,nt);
            dp[tmp]=max(dp[tmp],ans);
        }
        return ans;
    }
};

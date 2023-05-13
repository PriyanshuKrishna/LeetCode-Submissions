class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        long long ans=0,pow=1;
        int n=nums.size();
        vector<long long> pre(n,0);
        vector<long long> suf(n,0);
        pre[0]=nums[0];
        suf[n-1]=nums.back();
        
        for(int i=0;i<k;i++)
            pow*=2;
        
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]|nums[i];
            suf[n-i-1]=suf[n-i]|nums[n-i-1];
        }
        
        for(int i=0;i<n;i++){
            long long x=nums[i]*pow;
            if(i-1>=0)
                x=x|pre[i-1];
            if(i+1<n)
                x=x|suf[i+1];
            ans=max(ans,x);
        }
        return ans;
    }
};

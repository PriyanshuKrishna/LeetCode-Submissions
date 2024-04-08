class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n,0),pre(n,0),post(n,0);
        pre[0]=nums[0];
        post[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]*nums[i];
        }
        for(int i=n-2;i>=0;i--){
            post[i]=post[i+1]*nums[i];
        }
        for(int i=0;i<n;i++){
            if(i==0) res[i]=post[i+1];
            else if(i==n-1) res[i]=pre[n-2];
            else res[i]=pre[i-1]*post[i+1];
        }
        return res;
        // Approach 1
    }
};
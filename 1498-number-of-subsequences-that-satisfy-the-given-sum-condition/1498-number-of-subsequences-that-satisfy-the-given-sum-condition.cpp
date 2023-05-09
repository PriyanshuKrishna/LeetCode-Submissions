class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        long long mod=1e9+7;
        int n=nums.size();
        vector<int> arr(n);
        arr[0]=1;
        for(int i=1;i<n;i++){
            arr[i]=(2*arr[i-1])%mod;
        }
        int i=0,j=n-1;
        long long count=0;
        while(i<=j){
            if(nums[i]+nums[j]<=target){
                count+=arr[j-i];
                i++;
                count%=mod;
            }
            else
                j--;
        }
        return count;
    }
};

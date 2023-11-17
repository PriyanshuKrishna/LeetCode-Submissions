class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int maxi=INT_MIN;
        for(int i=0;i<n/2;i++){
            int tmp=nums[i]+nums[n-i-1];
            maxi=max(tmp,maxi);
        }
        return maxi;
    }
};
class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n=nums.size();
        if(n<=4) return 0;
        sort(nums.begin(),nums.end());
        int mini=INT_MAX;
        for(int i=0;i<4;i++){
            mini=min(mini,nums[n-3-1+i]-nums[i]);
        }
        return mini;
    }
};
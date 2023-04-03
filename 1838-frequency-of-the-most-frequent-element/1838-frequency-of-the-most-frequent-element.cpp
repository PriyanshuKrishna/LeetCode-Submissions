class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long long n=nums.size(),high=0,low=0,sum=0,maxi=0;
        while(high<n){
            sum+=nums[high];
            while(((high-low+1)*nums[high])>k+sum){
                sum-=nums[low];
                low++;
            }
            maxi=max(maxi,high-low+1);
            high++;
        }
        return maxi;
    }
};

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long int maxi=*max_element(nums.begin(),nums.end()),ans=0;
        int left=0,right=0,count=0;
        while(right<nums.size()){
            if(nums[right]==maxi)
                count++;
            while(count>=k){
                if(nums[left]==maxi)
                    count--;
                left++;
                ans+=(nums.size()-right);
            }
            right++;
        }
        return ans;
    }
};
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size(),cnt=0;
        for(int i=0;i+2<n;i++){
            if(nums[i]==0){
                cnt++;
                nums[i+1]=!nums[i+1];
                nums[i+2]=!nums[i+2];
            }
        }
        return (nums[n-1] && nums[n-2])?cnt:-1;
    }
};
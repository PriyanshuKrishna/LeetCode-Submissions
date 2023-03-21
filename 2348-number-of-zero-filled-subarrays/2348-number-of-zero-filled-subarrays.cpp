class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long rs=0,count=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0)  
                count++;
            else  
                count=0;
            rs+=count;
        }
        return rs;
    }
};
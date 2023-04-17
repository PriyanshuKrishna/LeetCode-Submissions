class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0,lsum=0;
        for(int i=0;i<nums.size();i++)
            sum+=nums[i];
        for(int i=0;i<nums.size();i++){
            if(lsum==(sum-lsum-nums[i]))
                return i;
            lsum+=nums[i];
        }
        return -1;
    }
};
class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size()-1;
        for(int i=0;i<n+1;i++){
            if(nums[i]!=min(n,i+1))
                return false;
        }
        return true;
    }
};

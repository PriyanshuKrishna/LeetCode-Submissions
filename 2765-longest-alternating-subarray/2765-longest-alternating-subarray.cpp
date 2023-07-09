class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int n=nums.size();
        int res=0;
        for(int i=0;i<n;i++){
            int t=1;
            for(int j=i+1;j<n;j++){
                if(nums[j]-nums[j-1]==t)
                    res=max(res,j-i+1);
                else
                    break;
                t=-t;
            }
        }
        if(res==0) return -1;
        return res;
    }
};

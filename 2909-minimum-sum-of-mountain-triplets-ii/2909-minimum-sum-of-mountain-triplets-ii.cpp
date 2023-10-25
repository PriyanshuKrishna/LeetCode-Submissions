class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> sright(n,nums.back());
        for(int i=n-2;i>=0;i--){
            sright[i]=min(sright[i+1],nums[i]);
        }
        int sleft=nums[0],mini=INT_MAX;
        for(int i=1;i<n;i++){
            if(sleft<nums[i] && sright[i]<nums[i])
                mini=min(mini,nums[i]+sright[i]+sleft);
            sleft=min(sleft,nums[i]);
        }
        return mini==INT_MAX?-1:mini;
    }
};

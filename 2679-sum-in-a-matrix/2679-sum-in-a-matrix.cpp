class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int sum=0;
        int m=nums.size(),n=nums[0].size();
        for(int i=0;i<m;i++){
            sort(nums[i].begin(),nums[i].end());
        }
        for(int i=0;i<n;i++){
            int maxi=INT_MIN;
            for(int j=0;j<m;j++){
                maxi=max(maxi,nums[j][i]);
            }
            sum+=maxi;
        }
        return sum;
    }
};

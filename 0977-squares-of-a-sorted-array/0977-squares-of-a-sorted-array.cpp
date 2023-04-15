class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int> res(n);
        int l=0,r=n-1;
        for(int k=r;k>=0;k--){
            if(abs(nums[r])>abs(nums[l]))
                res[k]=nums[r]*nums[r],r--;
            else
                res[k]=nums[l]*nums[l],l++;
        }
        return res;
    }
};
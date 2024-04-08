class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(),0);
        vector<int> pre(nums.size(),0);
        pre[0]=nums[0];
        vector<int> post(nums.size(),0);
        post[nums.size()-1]=nums[nums.size()-1];
        for(int i=1;i<nums.size();i++){
            pre[i]=pre[i-1]*nums[i];
        }
        for(int i=nums.size()-2;i>=0;i--){
            post[i]=post[i+1]*nums[i];
        }
        for(int i=0;i<nums.size();i++){
            if(i==0) res[i]=post[i+1];
            else if(i==nums.size()-1) res[i]=pre[nums.size()-2];
            else res[i]=pre[i-1]*post[i+1];
        }
        return res;
    }
};
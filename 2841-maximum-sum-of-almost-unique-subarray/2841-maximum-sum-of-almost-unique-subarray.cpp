class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        long long uni=0,maxi=0,sum=0;
        unordered_map<int,int> mp;
        for(int i=0,j=0;i<nums.size();i++){
            sum+=nums[i];
            mp[nums[i]]++;
            if(mp[nums[i]]==1)  uni++;
            if(i>=k){
                sum-=nums[j];
                mp[nums[j]]--;
                if(mp[nums[j]]==0) uni--;
                j++;
            }
            if(uni>=m)
                maxi=max(maxi,sum);
        }
        return maxi;
    }
};
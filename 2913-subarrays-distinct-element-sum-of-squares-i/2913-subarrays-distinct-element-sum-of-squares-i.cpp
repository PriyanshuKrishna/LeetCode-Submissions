class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n=nums.size(),res=0;
        for(int i=0;i<n;i++){
            unordered_map<int,int> mp;
            int count=0;
            for(int j=i;j<n;j++){
                mp[nums[j]]++;
                if(mp[nums[j]]==1)
                    count++;
                res+=(count*count);
            }
        }
        return res;
    }
};
class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int n=nums.size();
        set<int> s;
        int mini=INT_MAX;
        for(int i=x;i<n;i++){
            s.insert(nums[i-x]);
            auto it=s.lower_bound(nums[i]);
            if(it!=s.end())
                mini=min(mini,abs(nums[i]-*it));
            if(it!=s.begin()){
                it--;
                mini=min(mini,abs(nums[i]-*it));
            }
        }
        return mini;
       
    }
};

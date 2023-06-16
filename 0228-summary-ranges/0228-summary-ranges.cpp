class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int n=nums.size();
        if(n==0) return res;
        for(int i=0;i<n;i++){
            int tmp=nums[i];
            while(i+1<n && nums[i]+1==nums[i+1])
                i++;
            if(tmp!=nums[i])
                res.push_back(to_string(tmp)+"->"+to_string(nums[i]));
            else
                res.push_back(to_string(tmp));
        }
        return res;
    }
};

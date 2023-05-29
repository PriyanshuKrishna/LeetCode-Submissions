class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int n=nums.size(),count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                string tmp=(nums[i]+nums[j]);
                if(i!=j && tmp==target) 
                    count++;
            }
        }
        return count;
    }
};
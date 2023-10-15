class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        vector<int> res(2,-1);
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                if(abs(j-i)>=indexDifference && abs(nums[i]-nums[j])>=valueDifference)
                    return {i,j};
            }
        }
        return res;
    }
};
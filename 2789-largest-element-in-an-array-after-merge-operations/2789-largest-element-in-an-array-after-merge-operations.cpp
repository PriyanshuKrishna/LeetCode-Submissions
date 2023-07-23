class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        vector<long long> nums2;
        for(auto& it:nums){
            nums2.push_back(it);
        }
        for(int i=nums2.size()-1;i>0;i--){
            if(nums2[i-1]<=nums2[i]){
                nums2[i-1]=nums2[i-1]+nums2[i];
                nums2.erase(nums2.begin()+i);
            }
        }
        return *max_element(nums2.begin(),nums2.end());
    }
};

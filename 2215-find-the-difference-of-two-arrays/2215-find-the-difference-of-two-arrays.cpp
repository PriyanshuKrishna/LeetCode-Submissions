class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> n1(nums1.begin(),nums1.end());
        unordered_set<int> n2(nums2.begin(),nums2.end());
        vector<int> rs1,rs2;
        for(auto it:n1){
            if(!n2.count(it))
                rs1.push_back(it);
        }
        for(auto it:n2){
            if(!n1.count(it))
                rs2.push_back(it);
        }
        return {rs1,rs2};
    }
};

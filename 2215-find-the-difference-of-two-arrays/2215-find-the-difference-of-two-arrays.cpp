class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> res;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        set<int> n1,n2;
        for(int i=0;i<nums1.size();i++){
            n1.insert(nums1[i]);
        }
        for(int i=0;i<nums2.size();i++)
            n2.insert(nums2[i]);
        vector<int> tmp;
        for(int i=0;i<nums1.size();i++){
            if(i==0){
                if(!n2.count(nums1[i]))
                    tmp.push_back(nums1[i]);
            }
            else if(i>0 && nums1[i]!=nums1[i-1]){
                if(!n2.count(nums1[i]))
                    tmp.push_back(nums1[i]);
            }
        }
        res.push_back(tmp);
        vector<int> temp;
        for(int i=0;i<nums2.size();i++){
            if(i==0){
                if(!n1.count(nums2[i]))
                    temp.push_back(nums2[i]);
            }
            else if(i>0 && nums2[i]!=nums2[i-1]){
                if(!n1.count(nums2[i]))
                    temp.push_back(nums2[i]);
            }
        }
        res.push_back(temp);
        return res;
    }
};
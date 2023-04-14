class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> st;
        for(auto num: nums){
            if(st.find(num)!=st.end())
                return true;
            st.insert(num);
        }
        return false;
    }
};
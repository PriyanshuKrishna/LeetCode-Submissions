class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int> st;
        for(auto it:nums)
            st.insert(it);
        int sze=st.size();
        
        int n=nums.size(),count=0;
        for(int i=0;i<n;i++){
            unordered_set<int> tmp;
            for(int j=i;j<n;j++){
                tmp.insert(nums[j]);
                if(tmp.size()==sze)
                    count++;
            }
        }
        return count;
    }
};
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n,0);
        int pos=0,neg=1;
        for(auto it:nums){
            if(it>0){
                res[pos]=it;
                pos+=2;
            }
            else{
                res[neg]=it;
                neg+=2;
            }
        }
        return res;
    }
};
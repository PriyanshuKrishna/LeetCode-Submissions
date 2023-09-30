class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int,int> mp;
        for(auto it:nums){
            mp[it]++;
        }
        int count=0,two=0,three=0;
        for(auto it:mp){
            int freq=it.second;
            if(freq==1)
                return -1;
            else if(freq%3==0)
                count+=(freq/3);
            else
                count+=((freq/3)+1);
        }
        return count;
    }
};
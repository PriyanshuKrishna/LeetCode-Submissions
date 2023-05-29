class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int n=target.size(),count=0;
        unordered_map<string,int> mp;
        for(auto it:nums){
            mp[it]++;
        }
        for(int i=0;i<n;i++){
            string s1=target.substr(0,i);
            string s2=target.substr(i,n);
            if(s1==s2)
                count+=mp[s1]*(mp[s2]-1);
            else
                count+=mp[s1]*mp[s2];
        }
        return count;
    }
};
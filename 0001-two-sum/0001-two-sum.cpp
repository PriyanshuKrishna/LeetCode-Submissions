class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target){
        unordered_map<int,int> mp;
        for(int i=0;i<numbers.size();i++){
            int numtofind=target-numbers[i];
            if(mp.find(numtofind)!=mp.end())
                return {mp[numtofind],i};
            mp[numbers[i]]=i;
        }
        return {};
    }
};
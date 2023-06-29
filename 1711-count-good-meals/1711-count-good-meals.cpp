class Solution {
public:
    int countPairs(vector<int>& del) {
        unordered_map<int,int> mp;
        long long count=0,uplimit=pow(2,21);
        for(auto i:del){
            for(int j=1;j<=uplimit;j*=2){
                if(mp.count(j-i)){
                    count+=mp[j-i];
                }
            }
            mp[i]++;
        }
        return count%1000000007;
    }
};

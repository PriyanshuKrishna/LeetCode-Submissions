class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans=0,prior=0;
        for(auto &it:bank){
            int count=0;
            for(auto& c:it){
                if(c=='1') count++;
            }
            if(count){
                ans+=(prior*count);
                prior=count;
            }
        }
        return ans;
    }
};
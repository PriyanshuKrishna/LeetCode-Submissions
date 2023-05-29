class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        long long res=1;
        vector<int> pos,neg,zero;
        for(auto it:nums){
            if(it==0) zero.push_back(it);
            else if(it>0) pos.push_back(it);
            else neg.push_back(it);
        }
        sort(neg.begin(),neg.end());
        if(pos.size()>0){
            for(auto it:pos){
                res*=it;
            }
        }
        if(pos.empty() && neg.empty() && zero.size()>0) return 0;
        if(pos.empty() && neg.size()==1 && zero.size()>0) return 0;
        if(pos.empty() && neg.size()==1 ) return neg[0];

        for(int i=0;i<neg.size();i++){
            if(i%2){
                long long h=neg[i-1]*neg[i];
                res*=h;
            }
        }
        return res;
    }
};
class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        int res=0;
        special.push_back(bottom-1);
        special.push_back(top+1);
        sort(special.begin(),special.end());
        for(int i=1;i<special.size();i++){
            res=max(res,special[i]-special[i-1]-1);
        }
        return res;
    }
};
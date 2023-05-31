class Solution {
public:
    bool checkString(string s) {
        vector<int> tmp(2,0);
        tmp[1]=INT_MAX;
        for(int i=0;i<s.length();i++){
            if(s[i]=='a')
                tmp[0]=max(tmp[0],i);
            else
                tmp[1]=min(tmp[1],i);
        }
        return tmp[0]<=tmp[1]?true:false;
    }
};
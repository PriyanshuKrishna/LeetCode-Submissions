class Solution {
public:
    bool checkRecord(string s) {
        int absent=0,late=0;
        for(auto it:s){
            if(it=='A') absent++;
            if(absent>=2) return false;
            if(it=='L') late++;
            if(late>=3) return false;
            if(it!='L') late=0;
        }
        return true;
    }
};
/*
int n=s.length(),absent=0;
        for(int i=0;i<n;i++){
            if(absent>=2) return false;
            if(s[i]=='A') absent++;
        }
        for(int i=0;i<=n-3;i++){
            string tmp=s.substr(i,3);
            if(tmp=="LLL")  return false;
         }
        if(absent>=2) return false;
        return true;
        
*/
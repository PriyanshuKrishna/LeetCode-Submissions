class Solution {
public:
    int partitionString(string s) {
        int ans[26]={};
        int res=0,last=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(ans[s[i]-'a']>=last){
                res++;
                last=i+1;
            }
            ans[s[i]-'a']=i+1;
        }
        return res;
    }
};
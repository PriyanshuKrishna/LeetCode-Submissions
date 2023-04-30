class Solution {
public:
    bool backspaceCompare(string s, string t) 
    {
        bool ans=false;
        string s1="";
        string t1="";
        if(s[0]!='#')  
            s1=s[0];
        if(t[0]!='#')  
            t1=t[0];
        for(int i=1;i<s.size();i++)
        {
            if(s[i]!='#')
                s1+=s[i];
            else if(s[i]=='#' && s1.size() ==0)
                continue;
            else
                s1.pop_back();
        }
        for(int i=1;i<t.size();i++)
        {
            if(t[i]!='#')
                t1+=t[i];
            else if(t[i]=='#' && t1.size() ==0)
                continue;
            else
                t1.pop_back();
        }
        if(s1==t1)
            ans=true;
        
        return ans;
    }
};
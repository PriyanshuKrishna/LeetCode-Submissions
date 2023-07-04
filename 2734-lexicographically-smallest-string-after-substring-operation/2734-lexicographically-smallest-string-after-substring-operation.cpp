class Solution {
public:
    string smallestString(string s) {
        int i=0,flag=0;
        vector<char> v(26);
        int z=0;
        for(char x='a';x<='z';x++)
            v[z++]=x;
        while(i<s.size() && s[i]=='a') 
            i++;
        if(i==s.size()) 
            s[i-1]='z';
        for(int j=i;j<s.size();j++){
            if(s[j]=='a') flag=1;
            if(!flag)
                s[j]=v[s[j]-'a'-1];
        }
        return s;
    }
};

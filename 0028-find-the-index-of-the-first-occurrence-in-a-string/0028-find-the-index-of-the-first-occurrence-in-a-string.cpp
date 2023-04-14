class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=needle.size();
        string str="";
        for(int i=0;i<n;i++){
            str=str+haystack[i];
        }
        if(str==needle)
            return 0;
        for(int i=n;i<haystack.size();i++){
            if(str==needle)
                return (i-n);
            str+=haystack[i];
            str.erase(0,1);
        }
        if(str==needle)
            return haystack.size()-n;
        return -1;
    }
};
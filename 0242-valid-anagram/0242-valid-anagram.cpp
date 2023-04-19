class Solution {
public:
    bool isAnagram(string s, string t)
    {
        int s_count[26] = {0}, t_count[26] = {0};
        for(int i=0; i<s.size(); i++){
            s_count[s[i] - 'a']++;
        }
        for(int i=0; i<t.size(); i++){
            t_count[t[i] - 'a']++;
        }
        for(int i=0; i<26; i++){
            if(s_count[i] != t_count[i]) 
                return false;
            else 
                continue;
        }
        return true;
    }
};
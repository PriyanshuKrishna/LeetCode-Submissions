class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> occ(26,0);
        for(int i=0;i<s.size();i++){
            occ[t[i]-'a']++;
            occ[s[i]-'a']--;
        }
        int ans=0;
        for(int i=0;i<26;i++){
            ans+=max(0,occ[i]);
        }
        return ans;
    }
};
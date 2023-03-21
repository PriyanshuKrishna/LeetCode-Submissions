class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> s;
        int n=strs.size();
        map<string,vector<string>> mp;
        for(int i=0;i<n;i++){
            string st=strs[i];
            sort(st.begin(),st.end());
            mp[st].push_back(strs[i]);
        }
        for(auto it:mp){
            vector<string> temp;
            for(auto k:it.second)
                temp.push_back(k);
            s.push_back(temp);
        }
        return s;
    }
};
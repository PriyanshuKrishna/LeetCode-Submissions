class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> s;
        map<string,vector<string>> mp;
        for(int i=0;i<strs.size();i++){
            string str=strs[i];
            sort(str.begin(),str.end());
            mp[str].push_back(strs[i]);
        }
        for(auto it:mp){
            vector<string> temp;
            for(auto& k:it.second)
                temp.push_back(k);
            s.push_back(temp);
        }
        return s;
    }
};
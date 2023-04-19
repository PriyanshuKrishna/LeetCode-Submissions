class Solution {
public:
	int firstUniqChar(string s) 
    {
        unordered_map<char, pair<int, int>> umap;
        int idx = s.size();
        for (int i = 0; i < s.size(); i++) {
            umap[s[i]].first++;
            umap[s[i]].second = i;
        }
        for (const auto& [c, p] : umap) {
            if (p.first == 1) 
                idx = min(idx, p.second);
        }
        return idx == s.size() ? -1 : idx;
    }
};
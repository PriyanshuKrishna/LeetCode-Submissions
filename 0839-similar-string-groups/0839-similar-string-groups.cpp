class Solution {
private:
    bool isSimilar(string s1,string s2){
        int count=0;
        for(int i=0;i<s1.length();i++){
            if(s1[i]!=s2[i]){
                count++;
                if(count>2) 
                    return 0;
            }
        }
        return (count==2 || count==0);
    }
    void dfs(string str,vector<string>& strs,set<string>& vis){
        if(vis.count(str)>0) 
            return;
        vis.insert(str);
        for(int i=0;i<strs.size();i++){
            if(isSimilar(str,strs[i]))
                dfs(strs[i],strs,vis);
        }
    }
public:
    int numSimilarGroups(vector<string>& strs) {
        int rs=0;
        if(strs.empty()) 
            return 0;
        set<string> vis;
        for(string it:strs){
            if(vis.count(it)==0){
                dfs(it,strs,vis);
                rs++;
            }
        }
        return rs;
    }
};


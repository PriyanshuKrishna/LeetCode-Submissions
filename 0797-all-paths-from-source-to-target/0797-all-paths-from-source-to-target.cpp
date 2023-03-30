class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<vector<int>>& graph,vector<int>& temp,int node){
        temp.push_back(node);
        if(node==graph.size()-1)
            res.push_back(temp);
        for(auto it:graph[node])
            dfs(graph,temp,it);
        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> temp;
        dfs(graph,temp,0);
        return res;
    }
};

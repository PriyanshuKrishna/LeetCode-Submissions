class Solution {
public:
    void dfs(vector<vector<int>>& graph,vector<vector<int>>& res,vector<int>& temp,int node){
        temp.push_back(node);
        if(node==graph.size()-1)
            res.push_back(temp);
        for(auto it:graph[node])
            dfs(graph,res,temp,it);
        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> temp;
        dfs(graph,res,temp,0);
        return res;
    }
};

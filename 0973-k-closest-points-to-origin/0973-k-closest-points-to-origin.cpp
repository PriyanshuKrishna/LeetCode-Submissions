class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>,greater<>> mi;
        vector<vector<int>> res;
        for(int i=0;i<points.size();i++){
            int x=points[i][0],y=points[i][1];
            int ress=(int)pow(x,2) + (int)pow(y,2);
            mi.push({ress,{x,y}});
        }
        while(k>0){
            vector<int> temp;
            for(auto i:mi.top().second) 
                temp.push_back(i);
            mi.pop();
            res.push_back(temp); 
            k--;
        }
        return res;
    }
};
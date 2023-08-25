class Solution {
public:
    string reorganizeString(string s) {
        string str="";
        priority_queue<pair<int,char>> pq;
        unordered_map<char,int> mp;
        for(auto it:s){
            mp[it]++;
        }
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        
        while(pq.size()>1){
            auto t=pq.top();pq.pop();
            auto r=pq.top();pq.pop();
            
            str+=t.second;
            str+=r.second;
            
            t.first--;
            r.first--;
            
            if(t.first>0) pq.push(t);
            if(r.first>0) pq.push(r);
            
        }
        
        if(!pq.empty()){
            if(pq.top().first>1)
                return "";
            else
                str+=pq.top().second;
        }
        return str;
    }
};

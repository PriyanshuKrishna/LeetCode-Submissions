class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        for(auto ch:s){
            if(!st.empty() && st.top().first==ch){
                auto tmp=st.top();
                st.pop();
                st.push({ch,tmp.second+1});
            }
            else
                st.push({ch,1});
            
            if(st.top().second==k)
                st.pop();
        }
        string str="";
        while(!st.empty()){
            auto tmp=st.top();
            st.pop();
            while(tmp.second--)
                str+=tmp.first;
        }
        reverse(str.begin(),str.end());
        return str;
    }
};
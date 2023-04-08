class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> st;
        vector<int> vis(26,0),cnt(26,0);
        for(int i=0;i<s.length();i++)
            cnt[s[i]-'a']++;
        for(int i=0;i<s.length();i++){
            cnt[s[i]-'a']--;
            if(vis[s[i]-'a'])
                continue;
            while(!st.empty() && s[i]<st.top() && cnt[st.top()-'a']!=0){
                vis[st.top()-'a']=0;
                st.pop();
            }
            st.push(s[i]);
            vis[s[i]-'a']=1;
        }
        s.clear();
        while(!st.empty()){
            s=st.top()+s;
            st.pop();
        }
        return s;
    }
};

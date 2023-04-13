class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n=pushed.size();
        stack<int> st;
        int h=0;
        for(int i=0;i<n;i++){
            st.push(pushed[i]);
            while(!st.empty() && h<n && st.top()==popped[h]){
                st.pop();
                h++;
            }
        }
        return (h==n);
    }
};
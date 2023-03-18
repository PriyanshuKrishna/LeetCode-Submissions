class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        stack<int> st;
        for(int i=0;i<n;i++){
            if(asteroids[i]>0 || st.empty())
                st.push(asteroids[i]);
            else{
                while(!st.empty() && st.top()>0 && st.top()<abs(asteroids[i]))
                    st.pop();
                if(!st.empty() && st.top()==abs(asteroids[i]))
                    st.pop();
                else{
                    if(st.empty() || st.top()<0)
                        st.push(asteroids[i]);
                }
            }
        }
        int sze=st.size();
        vector<int> rs(sze);
        for(int i=sze-1;i>=0;i--){
            rs[i]=st.top();
            st.pop();
        }
        return rs;
    }
};

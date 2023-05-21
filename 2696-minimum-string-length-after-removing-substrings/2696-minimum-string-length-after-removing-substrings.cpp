class Solution {
public:
    int minLength(string s) {
        stack<char> str;
        for(auto it:s){
            if(it=='B' && str.size() && str.top()=='A')
                str.pop();
            else if(it=='D' && str.size() && str.top()=='C')
                str.pop();
            else
                str.push(it);
        }
        return str.size();
    }
};

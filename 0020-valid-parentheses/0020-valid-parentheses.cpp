class Solution {
public:
    bool isValid(string s) {
        stack<char> str;
        for(auto i:s){
            if(i=='(' || i=='{' || i=='[')
                str.push(i);
            else{
                if(str.empty())
                    return false;
                if(i==')' && str.top()!='(')
                    return false;
                if(i=='}' && str.top()!='{')
                    return false;
                if(i==']' && str.top()!='[')
                    return false;
                str.pop();
            }
        }
        return str.empty();
    }
};
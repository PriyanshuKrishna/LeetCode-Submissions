class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> s;
        long long res=0;
        if(tokens.size()==1){
            int result=stoi(tokens[0]);
            return (result);
        }
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="/" || tokens[i]=="*"){
                string s1=s.top();s.pop();
                string s2=s.top();s.pop();
                long long fist=stoll(s1);
                long long sec=stoll(s2);
                if(tokens[i]=="+"){
                    res=(fist+sec);
                }
                else if(tokens[i]=="-"){
                    res=(sec-fist);
                }
                else if(tokens[i]=="/"){
                    res=(sec/fist);
                }
                else if(tokens[i]=="*"){
                    res=(fist*sec);
                }
                string s3=to_string(res);
                s.push(s3);
            }
            else
                s.push(tokens[i]);
        }
        return res;
    }
};
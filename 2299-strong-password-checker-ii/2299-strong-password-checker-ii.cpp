class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        int n=password.size();
        if(n<8)  
            return false;
        bool low=false,up=false,dig=false,sp=false;
        for(auto it:password){
            if(it>='a' && it<='z') low=true;
            else if(it>='A' && it<='Z') up=true;
            else if(isdigit(it)) dig=true;
            else sp=true;
        }
        for(int i=0;i<n-1;i++){
            if(password[i]==password[i+1]) 
                return false;
        }
        if(low && up && dig && sp) 
            return true;
        else
            return false;
    }
};
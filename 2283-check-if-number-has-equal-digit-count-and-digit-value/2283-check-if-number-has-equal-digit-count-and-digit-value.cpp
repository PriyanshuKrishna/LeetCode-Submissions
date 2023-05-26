class Solution {
public:
    bool digitCount(string num) {
        vector<int> freq(10,0);
        
        for(auto it:num){
            int nu=it-'0';
            freq[nu]++;
        }
        for(int i=0;i<num.length();i++){
            int nu=num[i]-'0';
            if(freq[i]!=nu)  
                return false;
        }
        return true;
    }
};
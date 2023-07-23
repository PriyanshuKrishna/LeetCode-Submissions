class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> res;
        
        for(auto it:words){
            
            string str="";
            for(auto j:it){
                if(j!=separator)
                    str+=j;
                else if(j==separator && !str.empty()){
                    res.push_back(str);
                    str="";
                }
            }
            if(!str.empty())
                res.push_back(str);
            
        }
        return res;
    }
};
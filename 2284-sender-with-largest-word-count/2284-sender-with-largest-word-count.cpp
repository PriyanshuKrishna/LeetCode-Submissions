class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        map<string , int> mp;
        for(int i=0;i<senders.size();i++){
            int count=1;
            for(int j=0;j<messages[i].length();j++){
                if(messages[i][j]==' ') 
                    count++;
            }
            mp[senders[i]]+=count;
        }
        string ans="";
        int maxi=0;
        for(auto it:mp){
            int freq=it.second;
            string tmp=it.first;
            if(maxi<=freq){
                maxi=freq;
                ans=tmp;
            }
        }
        return ans;
    }
};


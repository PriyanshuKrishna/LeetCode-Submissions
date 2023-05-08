class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> rs;
        int count=0;
        vector<int> arr(n,0);
        
        for(auto it:queries){
            int ind=it[0];
            int col=it[1];
            
            if(arr[ind] && ind-1>=0 && arr[ind-1]==arr[ind])
                count--;
            if(arr[ind] && ind+1<n && arr[ind+1]==arr[ind])
                count--;
            
            arr[ind]=col;
            
            if(ind-1>=0 && arr[ind-1]==arr[ind]) 
                count++;
            if(ind+1<n && arr[ind+1]==arr[ind]) 
                count++;
            
            rs.push_back(count);
        }
        return rs;
    }
};

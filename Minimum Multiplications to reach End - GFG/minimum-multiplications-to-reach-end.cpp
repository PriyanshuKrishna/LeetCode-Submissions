//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        int mod=100000;
        vector<int> dist(mod,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> q;
        dist[start]=0;
        q.push({0,start});
        while(!q.empty()){
            auto it=q.top();q.pop();
            int step=it.first;
            int node=it.second;
            
            for(auto it:arr){
                int num=(it*node)%mod;
                if(step+1<dist[num]){
                    dist[num]=step+1;
                    if(num==end)  return step+1;
                    q.push({step+1,num});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends
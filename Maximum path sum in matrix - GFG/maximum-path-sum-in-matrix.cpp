//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int n, vector<vector<int>> matrix)
    {
        // code here
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            dp[n-1][i]=matrix[n-1][i];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int f=matrix[i][j],s=matrix[i][j],t=matrix[i][j];
                if(j==0){
                    s+=dp[i+1][j];
                    t+=dp[i+1][j+1];
                    dp[i][j]=max(t,s);
                }
                else if(j==n-1){
                    f+=dp[i+1][j-1];
                    s+=dp[i+1][j];
                    dp[i][j]=max(f,s);
                }
                else{
                    f+=dp[i+1][j-1];
                    s+=dp[i+1][j];
                    t+=dp[i+1][j+1];
                    dp[i][j]=max({f,s,t});
                }
            }
        }
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(maxi,dp[0][i]);
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
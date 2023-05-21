//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int ind,int target,int arr[],vector<vector<int>>& dp){
        if(target==0)  return 0;
        if(ind==0)  return(arr[ind]==target);
        if(dp[ind][target]!=-1)  return dp[ind][target];
        bool notpick=solve(ind-1,target,arr,dp);
        bool pick=false;
        if(arr[ind]<=target)
            pick=solve(ind-1,target-arr[ind],arr,dp);
        return dp[ind][target]=(pick | notpick);
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum=0,n=N;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        if(sum%2) return 0;
        vector<vector<int>> dp(n,vector<int>(sum,-1));
        return solve(n-1,sum/2,arr,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends
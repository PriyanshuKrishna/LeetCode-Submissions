//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int solve(int ind,int arr[],vector<vector<int>>& dp,int target){
	    int m=1e9+7;
	    if(target<0) return 0;
	    if(ind<0)
	        return (target==0);
	    if(dp[ind][target]!=-1)  return dp[ind][target];
	    int notake=solve(ind-1,arr,dp,target);
	    int take=0;
	    if(arr[ind]<=target)
	        take=solve(ind-1,arr,dp,target-arr[ind]);
	    
	    return dp[ind][target]=(notake+take)%m;
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return solve(n-1,arr,dp,sum);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends
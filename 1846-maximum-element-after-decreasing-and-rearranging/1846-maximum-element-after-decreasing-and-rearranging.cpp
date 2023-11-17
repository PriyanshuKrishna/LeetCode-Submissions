class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int res=0;
        if(arr.size()==1) return 1;
        if(arr[0]!=1) arr[0]=1;
        for(int i=1;i<arr.size();i++){
            if(abs(arr[i]-arr[i-1])<=1){
                res=max(arr[i],arr[i-1]);
            }
            else{
                arr[i]=min(arr[i],arr[i-1])+1;
                res=arr[i];
            }
        }
        return res;
    }
};
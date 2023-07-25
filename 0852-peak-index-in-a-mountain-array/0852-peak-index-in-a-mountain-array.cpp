class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int maxi=INT_MIN,res=0;
        for(int i=0;i<arr.size();i++){
            if(maxi<arr[i]){
                maxi=arr[i];
                res=i;
            }
        }
        return res;
        /*int lo=0,hi=arr.size();
        while(lo<hi)
        {
            int mid=lo+(hi-lo)/2;
            if(arr[mid]<arr[mid+1])
                lo=mid+1;
            else
                hi=mid;
        }
        return lo;*/
    }
};
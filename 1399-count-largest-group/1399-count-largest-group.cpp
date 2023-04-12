class Solution {
public:
    int countLargestGroup(int n) {
        vector<int> arr(37,0);
        int maxi=0,count=0;
        for(int i=1;i<=n;i++){
            int num=i,sum=0;
            while(num>0){
                sum+=num%10;
                num/=10;
            }
            ++arr[sum];
            if(maxi<arr[sum])
                maxi=arr[sum],count=1;
            else if(maxi==arr[sum])
                count++;
        }
        return count;
    }
};

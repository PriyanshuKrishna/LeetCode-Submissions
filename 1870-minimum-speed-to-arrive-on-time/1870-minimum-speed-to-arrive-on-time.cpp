class Solution {
private:
    bool check(vector<int>& dist,double& hour,int mid){
        double count=0;
        for(int i=0;i<dist.size()-1;i++)
            count+=ceil((double)dist[i]/mid);
        count+=((double)dist.back())/mid;
        return (count<=hour);
    }
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n=dist.size();
        if(n>ceil(hour)) return -1;
        int l=1,h=1e7,rs=-1;
        while(l<=h){
            int mid=(h+l)/2;
            if(check(dist,hour,mid)){
                rs=mid;
                h=mid-1;
            }
            else
                l=mid+1;
        }
        return rs;
    }
};

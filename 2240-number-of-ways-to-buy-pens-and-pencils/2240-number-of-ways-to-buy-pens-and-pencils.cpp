class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long ways=0,pcost=0;
        while(pcost<=total){
            long long ramount=total-pcost;
            long long pencil=ramount/cost2+1;
            ways+=pencil;
            pcost+=cost1;
        }
        return ways;
    }
};

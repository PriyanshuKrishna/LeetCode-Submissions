class Solution {
private:
    int check(string &str,char ch,int &k){
        int low=0,res=0,n=str.length(),count=0;
        for(int i=0;i<n;i++){
            if(str[i]==ch)
                count++;
            while(count>k){
                if(str[low]==ch)
                    count--;
                low++;
            }
            res=max(i-low+1,res);
        }
        return res;
    }
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(check(answerKey,'T',k),check(answerKey,'F',k));
    }
};
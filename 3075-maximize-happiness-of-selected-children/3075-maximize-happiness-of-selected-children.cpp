class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(),happiness.end());
        int i1=0;
        long long som=0;
        reverse(happiness.begin(),happiness.end());
        for(int i=0;i<k;i++){
            if(happiness[i]<i1){som+=0;i1++;}
            else{
            som+=happiness[i];
            som+=-i1;
            i1++;}
            

        }
    return som;
    }
};
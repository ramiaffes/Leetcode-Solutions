class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        vector<int>dp(arr.size());
        if(arr[0]%2==1)dp[0]=1;
        for(int i=1;i<arr.size();i++){
            if(arr[i]%2==1){
                dp[i]=((i)-dp[i-1]+1)%1000000007;
            }
        else{
            dp[i]=dp[i-1];
        }
        }
    int som=0;
    for(int i=0;i<arr.size();i++){
        som+=dp[i];
        som=som%1000000007;
    }
    return som;
    }
};
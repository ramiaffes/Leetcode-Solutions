class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n=nums.size();
        vector<long long int>dp(n);
        dp[0]=nums[0];
        for(long long int i(1);i<n;i++){
            dp[i]=dp[i-1];
            dp[i]+=nums[i];
        }
    vector<long long int>dp1(n);
    vector<long long int>dp2(n);
    dp1[0]=dp[0];
    for(long long int i(1);i<n;i++){
        dp1[i]=dp1[i-1];
        dp1[i]=min(dp[i],dp1[i]);
    }
    dp2[0]=dp[0];
    for(long long int i(1);i<n;i++){
        dp2[i]=dp2[i-1];
        dp2[i]=max(dp[i],dp2[i]);
    }
long long int ans=0;
for(long long int i(1);i<n;i++){
    ans=max(ans,abs(dp[i]-dp2[i-1]));
    ans=max(ans,abs(dp[i]-dp1[i-1]));
}
for(long long int i(0);i<n;i++){
    ans=max(ans,abs(dp[i]));
}
    return ans;
    }
};
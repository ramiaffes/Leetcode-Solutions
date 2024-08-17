class Solution {
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
    vector<vector<int>>dp(nums1.size(),vector<int>(2));
    dp[nums1.size()-1][0]=1;
    dp[nums1.size()-1][1]=1;
    int ans=1;
    for(int i=nums1.size()-2;i>=0;i--){
        dp[i][0]=1;
        if(nums1[i+1]>=nums1[i]){
            dp[i][0]=max(dp[i+1][0]+1,dp[i][0]);
        }
        if(nums2[i+1]>=nums1[i]){
            dp[i][0]=max(dp[i+1][1]+1,dp[i][0]);
        }
    dp[i][1]=1;
        if(nums1[i+1]>=nums2[i]){
            dp[i][1]=max(dp[i+1][0]+1,dp[i][1]);
        }
        if(nums2[i+1]>=nums2[i]){
            dp[i][1]=max(dp[i+1][1]+1,dp[i][1]);
        }
    ans=max(ans,dp[i][1]);
    ans=max(ans,dp[i][0]);
    }
    return ans;
    }
};
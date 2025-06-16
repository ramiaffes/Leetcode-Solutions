class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        vector<int>dp(nums.size()); 
        int res=-1;
        dp[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            if(dp[i-1]<nums[i])
            res=max(res,nums[i]-dp[i-1]);
            dp[i]=min(dp[i-1],nums[i]);
        }
   
    
    return res;
    }
};
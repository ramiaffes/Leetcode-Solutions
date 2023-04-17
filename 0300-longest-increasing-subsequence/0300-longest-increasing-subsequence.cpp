class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size());
        int som=0;
        for(int i=0;i<nums.size();i++){
            dp[i]=1;
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i])
                dp[i]=max(dp[i],dp[j]+1);
            }
        
        }
        
    
    for(auto v:dp){
        som=max(v,som);
    }
    return som;
    }
};
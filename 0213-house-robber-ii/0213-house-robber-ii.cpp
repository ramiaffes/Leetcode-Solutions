class Solution {
public:
    map<int,int>dp;
    map<int,bool>vis;
    void func(int i,vector<int>nums){
        vis[i]=1;
        dp[i]=nums[i];
        for(int j=i+2;j<(nums.size());j++){
            if(vis[j]==0){
                func(j,nums);
            }
            dp[i]=max(dp[j]+nums[i],dp[i]);
        }
    }
    void func2(int i,vector<int>nums){
        vis[i]=1;
        dp[i]=nums[i];
        for(int j=i+2;j<(nums.size()-1);j++){
            if(vis[j]==0){
                func2(j,nums);
            }
            dp[i]=max(dp[j]+nums[i],dp[i]);
        }
    }
    int rob(vector<int>& nums) {
        dp.clear();
        vis.clear();
        int ans=0;
        for(int i=1;i<nums.size();i++){ func(i,nums);ans=max(ans,dp[i]);}
        vis.clear();dp.clear();
        func2(0,nums);ans=max(ans,dp[0]);
       
        return ans;
    }
};
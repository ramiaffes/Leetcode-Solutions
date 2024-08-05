class Solution {
public:
    map<pair<int,int>,bool>dp;
    map<pair<int,int>,bool>vis;
    void func(vector<int> nums,int i,int j,int m,int som){
        
        vis[make_pair(i,j)]=1;
        if((i==j)){dp[make_pair(i,j)]=1;return;}
        if(som<m){dp[make_pair(i,j)]=0;return;}
        if(((j-i+1)<=2)){dp[make_pair(i,j)]=1;return;}
        if(vis[make_pair(i+1,j)]==0)
        func(nums,i+1,j,m,som-nums[i]);
        if(vis[make_pair(i,j-1)]==0)
        func(nums,i,j-1,m,som-nums[j]);
        dp[make_pair(i,j)]=((dp[make_pair(i+1,j)])or(dp[make_pair(i,j-1)]));
        
        
    }
    bool canSplitArray(vector<int>& nums, int m) {
        if(nums.size()<=2)return true;
        dp.clear();
        vis.clear();
        int som=0;
        for(int i=0;i<nums.size();i++)som+=nums[i];
        func(nums,0,nums.size()-1,m,som);
        return dp[make_pair(0,nums.size()-1)];
        }
};
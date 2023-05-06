int som1=0;
map<int,vector<int>>adj;
map<pair<int,int>,int>dp;
void dfs(int u,int som,int target){
    som+=u;  
    if(dp[make_pair(som,u)]!=0)return;
    if(som==target){dp[make_pair(som,u)]=1;return;}
    else if(som>target){dp[make_pair(som,u)]=-1;return;}
    for(auto v:adj[u]){if(dp[make_pair(som+v,v)]==0)dfs(v,som,target);}
    for(auto v:adj[u]){
        if(dp[make_pair(som+v,v)]!=-1)
        dp[make_pair(som,u)]+=dp[make_pair(som+v,v)];
    }
    if(dp[make_pair(som,u)]==0)dp[make_pair(som,u)]=-1;
}
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        som1=0;
        adj.clear();
        dp.clear();
        for(auto v:nums)
        {
            for(auto v1:nums){
                adj[v].push_back(v1);
            }
        }
        for(auto v:nums){
        dfs(v,0,target);if(dp[make_pair(v,v)]!=-1)som1+=dp[make_pair(v,v)];}
        return som1;
    }
};
map<int,vector<int>>adj;
map<int, int>dp;
map<int, int>dp1;
string s1;
void dfs(int u){ 
    dp[u]=1;
    dp1[u]=1;
    int ans=0;
    int ans1=0;
    int cnt=0;
    for(auto v:adj[u]){  
        if(dp[v]==0)dfs(v); if((s1[v]!=s1[u])){
        dp[u]=max(dp[u],dp[v]+1);
         ans=max(ans,dp[v]);}
    }
     for(auto v:adj[u]){ 
         
       if((s1[v]!=s1[u])){
        if(ans==dp[v])cnt++;
           if(dp[v]!=ans)
       ans1=max(ans1,dp[v]);}
    }
    if(cnt>1)dp1[u]+=2*ans;
else dp1[u]+=(ans+ans1);
}

class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        adj.clear();
        dp.clear();
        dp1.clear();
        for(int i=0;i<parent.size();i++){
            if(parent[i]!=-1)
            adj[parent[i]].push_back(i);
        }
        s1=s;
        int ans=0;
        dfs(0);
        for(auto v:dp1){
            ans=max(ans,v.second);
        }
        return ans;
        
    }
};
map<pair<int,int>,vector<pair<int,int>>>adj;
map<pair<int,int>,long long int>dp;
void dfs(pair<int,int>u){ 
    dp[u]=1;
    for(auto v:adj[u]){
        if(dp[v]==0)dfs(v);
        dp[u]+=(dp[v]%1000000007);
    }
}
class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        adj.clear();
        dp.clear();
        int n=grid.size();
        int m=grid[0].size();
          for(long long int i(0);i<n;i++){
            for(long long int j(0);j<(m-1);j++){
                if((grid[i][j]<grid[i][j+1])){
                adj[make_pair(i,j)].push_back(make_pair(i,j+1));}
                else if(grid[i][j]!=grid[i][j+1])
                adj[make_pair(i,j+1)].push_back(make_pair(i,j));
            }
        }
          for(long long int i(0);i<m;i++){
            for(long long int j(0);j<(n-1);j++){
                if((grid[j][i]<grid[j+1][i])){
                adj[make_pair(j,i)].push_back(make_pair(j+1,i));}
                else if(grid[j][i]!=grid[j+1][i])
                adj[make_pair(j+1,i)].push_back(make_pair(j,i));
            }
        }
    for(long long int i(0);i<n;i++){
            for(long long int j(0);j<(m);j++){
    if(dp[make_pair(i,j)]==0)dfs(make_pair(i,j));}}
    long long int ans=0;
    for(auto v:dp){
        ans+=(v.second)%1000000007;
        
    }
    
        
        
     return ans%1000000007;   
    }
};
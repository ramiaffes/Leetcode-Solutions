map<pair<int,int>,vector<pair<int,int>>>adj;
map<pair<int,int>, int>dp;
map<pair<int,int>,bool>vis;
void dfs(pair<int,int>u){ vis[u]=1;
    dp[u]=1;
    for(auto v:adj[u]){
        if(vis[v]==0)dfs(v);
        dp[u]=max(dp[u],dp[v]+1);
    }
}
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vis.clear();
        adj.clear();
        dp.clear();
        int n=matrix.size();
        int m=matrix[0].size();
          for(long long int i(0);i<n;i++){
            for(long long int j(0);j<(m-1);j++){
                if((matrix[i][j]<matrix[i][j+1])){
                adj[make_pair(i,j)].push_back(make_pair(i,j+1));}
                else if(matrix[i][j]!=matrix[i][j+1])
                adj[make_pair(i,j+1)].push_back(make_pair(i,j));
            }
        }
          for(long long int i(0);i<m;i++){
            for(long long int j(0);j<(n-1);j++){
                if((matrix[j][i]<matrix[j+1][i])){
                adj[make_pair(j,i)].push_back(make_pair(j+1,i));}
                else if(matrix[j][i]!=matrix[j+1][i])
                adj[make_pair(j+1,i)].push_back(make_pair(j,i));
            }
        }
    for(long long int i(0);i<n;i++){
            for(long long int j(0);j<(m);j++){
    if(vis[make_pair(i,j)]==0)dfs(make_pair(i,j));}}
    int ans=0;
    for(auto v:dp){
        ans=max(ans,v.second);
    }
    
        
        
     return ans;   
    }
};
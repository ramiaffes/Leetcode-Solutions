class Solution {
public:
    int ans=0;
    int som=0;
    map<pair<int,int>,bool>vis;
    map<pair<int,int>,vector<pair<int,int>>>adj;
    vector<vector<int>>grid1;
     void dfs(pair<int,int>u){
        if(vis[u])return;
        vis[u]=1;
        som+=grid1[u.first][u.second];
        ans=max(ans,som);
        for(auto v:adj[u]){
            dfs(v);
        }

     }
    int findMaxFish(vector<vector<int>>& grid) {
        adj.clear();
        vis.clear();
        grid1=grid;
        ans=0;
        som=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]>=1){
                    if((i<(grid.size()-1))and(grid[i+1][j]>=1)){
                        adj[make_pair(i,j)].push_back(make_pair(i+1,j));
                        adj[make_pair(i+1,j)].push_back(make_pair(i,j));
                    }
                    if((j<(grid[0].size()-1))and(grid[i][j+1]>=1)){
                        adj[make_pair(i,j)].push_back(make_pair(i,j+1));
                        adj[make_pair(i,j+1)].push_back(make_pair(i,j));
                    }

                }
            }
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                dfs(make_pair(i,j));som=0;
            }}
    return ans;
    }
};
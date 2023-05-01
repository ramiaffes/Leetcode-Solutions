map<pair<int,int>,vector<pair<int,int>>>adj;
int som=0;
void dfs(pair<int,int>u,map<pair<int,int>,bool>vis,pair<int,int>v1,int som1,int som2){ 
    som2++;
    vis[u]=1;
    if((u==v1)and(som2==som1)){som++;return;}
    for(auto v:adj[u]){
        if(vis[v]==0)
        dfs(v,vis,v1,som1,som2);}
}
class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
         int n=grid.size();
        int m=grid[0].size();
        adj.clear();
        som=0;
        pair<int,int>u=make_pair(0,0);
         pair<int,int>v1=make_pair(0,0);
        for(long long int i(0);i<n;i++){
            for(long long int j(0);j<(m-1);j++){
                if((grid[i][j]!=-1)and(grid[i][j+1]!=-1)){
                adj[make_pair(i,j)].push_back(make_pair(i,j+1));
                adj[make_pair(i,j+1)].push_back(make_pair(i,j));}
                if(grid[i][j]==1){
                    u=make_pair(i,j);
                }
                if(grid[i][j+1]==1){
                    u=make_pair(i,j+1);}
            if(grid[i][j]==2){
                    v1=make_pair(i,j);
                }
                if(grid[i][j+1]==2){
                    v1=make_pair(i,j+1);}
            }
        } 
        for(long long int j(0);j<(m);j++){
         for(long long int i(0);i<(n-1);i++){
                if((grid[i][j]!=-1)and(grid[i+1][j]!=-1)){
                adj[make_pair(i,j)].push_back(make_pair(i+1,j));
                adj[make_pair(i+1,j)].push_back(make_pair(i,j));}
            }
        }
        int som1=0;
        for(long long int j(0);j<(m);j++){
         for(long long int i(0);i<(n);i++){
             if(grid[i][j]!=-1)som1++;
         }}
    map<pair<int,int>,bool>vis;
    dfs(u,vis,v1,som1,0);
    return som;
    }
};
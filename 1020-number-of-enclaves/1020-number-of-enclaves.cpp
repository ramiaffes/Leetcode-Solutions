map<pair<int,int>,vector<pair<int,int>>>adj;
map<pair<int,int>,bool>vis;
bool test=false;
int som=0;
void dfs(pair<int,int> u,int n,int m){
	if(vis[u]==1)return;
	vis[u]=1;
    som++;
    if((u.first==0)or(u.first==(n-1))or(u.second==0)or(u.second==(m-1))){
        test=true;
    }
	for(auto v:adj[u]){
		dfs(v,n,m);
		}}
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
       adj.clear();
         som=0;
        int res=0;
        vis.clear();
        int m=grid[0].size();
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<(m-1);j++){
                if((grid[i][j]==1)and(grid[i][j+1]==1)){
                    adj[make_pair(i,j)].push_back(make_pair(i,j+1));
                    adj[make_pair(i,j+1)].push_back(make_pair(i,j));
                }
            }
        }
    for(int j=0;j<m;j++){
        for(int i=0;i<(grid.size()-1);i++){
              if((grid[i][j]==1)and(grid[i+1][j]==1)){
                    adj[make_pair(i,j)].push_back(make_pair(i+1,j));
                    adj[make_pair(i+1,j)].push_back(make_pair(i,j));
                }
        }
    }
   for(int j=0;j<m;j++){
        for(int i=0;i<(grid.size());i++){
            if((vis[make_pair(i,j)]==0)and(grid[i][j]==1)){
                test=false;
                som=0;
                dfs(make_pair(i,j),grid.size(),m);
                if(test==false){
                    res+=som;
                }
            }
        }}
    return res;
    
     
 
    }
};
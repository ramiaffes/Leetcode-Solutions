map<pair<int,int> ,vector< pair<int,int> >>adj;
map< pair<int,int> ,bool>vis;
 map<pair<int,int>,int>hashing1;
int ans=0;
void dfs( pair<int,int> u,int val){
	if(vis[u]==1)return;
	vis[u]=1;
    hashing1[u]=val;
	for(auto v:adj[u]){
		if(vis[v]){
			continue;}
		dfs(v,val);}}
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        vis.clear();
        adj.clear();
        ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<(n-1);j++){
                if((grid[i][j]==1)and(grid[i][j+1]==1)){
                    adj[make_pair(i,j)].push_back(make_pair(i,j+1));
                    adj[make_pair(i,j+1)].push_back(make_pair(i,j));
                }
            }
        }
     for(int i=0;i<n;i++){
            for(int j=0;j<(n-1);j++){
                if((grid[j][i]==1)and(grid[j+1][i]==1)){
                    
                    adj[make_pair(j,i)].push_back(make_pair(j+1,i));
                    adj[make_pair(j+1,i)].push_back(make_pair(j,i));
                }
            }
        }
   
    int val=1;
    for(int i=0;i<n;i++){
            for(int j=0;j<(n);j++){
                if((vis[make_pair(i,j)]==0)and(grid[i][j]==1)){dfs(make_pair(i,j),val);
                                                               val++;
            }}}
    map<int,int>hashing2;
    for(int i=0;i<n;i++){
            for(int j=0;j<(n);j++){
                if(grid[i][j]==1){
                    hashing2[hashing1[make_pair(i,j)]]++;
                }
            }}
    for(auto v:hashing2){
        ans=max(ans,hashing2[v.first]);
    }
    for(int i=0;i<n;i++){
            for(int j=0;j<(n);j++){
                   if(grid[i][j]==0){
                    int som=0;
                     set<int>se;
                if(j>=1){
                    if(grid[i][j-1]==1)se.insert(hashing1[make_pair(i,j-1)]);
                }
            if(j<(n-1)){
                if(grid[i][j+1]==1){
                    se.insert(hashing1[make_pair(i,j+1)]);
                }
            }
            if(i<(n-1)){
                 if(grid[i+1][j]==1){
                    se.insert(hashing1[make_pair(i+1,j)]);
                }
            }
            if(i>=1){
                if(grid[i-1][j]==1){
                    se.insert(hashing1[make_pair(i-1,j)]);
                }
            }
            for(auto v:se)som+=hashing2[v];
                       ans=max(ans,som+1);
                       
                }
            }}
    
    return ans;    
    
        
    }
};
map<int, int>tin;
map< int, int>tout;
int timer=0;
map<int,map<int,int>>dp;
vector<int>res;
map<int,bool>vis;
map<int,vector<int>>adj;
void dfs( int u){
    vis[u]=1;
    
    for(auto v:adj[u]){
        if(dp[u][v]==1)continue;
        dp[u][v]=1;
        if(vis[v]==1){
            for(auto v1:dp[v]){
                dp[u][v1.first]=1;
            }continue;
        }
        dfs(v);
        for(auto v1:dp[v]){
                dp[u][v1.first]=1;
            }
    } 
		}
bool isancestor( int u, int v){
	return (tin[u]<=tin[v]) and (tout[u]>=tout[v]);}

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        dp.clear();
        vis.clear();
        adj.clear();
        map<int,int>hashing;
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            hashing[prerequisites[i][0]]=1;
            
        }
vector<bool>answers(queries.size());
for(int i=0;i<numCourses;i++){
    if(hashing[i]==0){dfs(i);}
}
for(int i=0;i<queries.size();i++){
    if(dp[queries[i][1]][queries[i][0]])answers[i]=1;
}
return answers;
    

    }
};
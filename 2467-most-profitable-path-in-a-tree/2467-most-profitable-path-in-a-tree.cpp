class Solution {
public:
    map<int ,vector<int>>adj;
    map< int ,bool>vis;
    map<int, int>tin;
    map< int, int>tout;
    vector<int>amount1;
    int ans=-1e9;
    int timer=0;
    int val=0;
    void dfs(int u,int som,int bob){
    if(u==bob){val=som;}
	if(vis[u]==1)return;
	vis[u]=1;
	tin[u]=timer++;
	if(adj[u].empty())return;
	for(auto v:adj[u]){
		if((vis[v]))continue;
		dfs(v,som+1,bob);
		}
		tout[u]=timer++;}
    bool isancestor(int u,int v){
	return (tin[u]<=tin[v]) and (tout[u]>=tout[v]);}
    void dfs2(int u,int val,int bob,int som,int som1){
	if(vis[u]==1)return;
	vis[u]=1;
    if(isancestor(u,bob)){
        if((val%2==1)and((som1-1)==(val/2))){

            som+=amount1[u]/2;
        }
        else if(som1>(val/2)) som=som;
        else som+=amount1[u];

    }
    else som+=amount1[u];
	for(auto v:adj[u]){
        if((vis[v])and(adj[u].size()==1)){ans=max(ans,som);continue;}
		if((vis[v]))continue;
		dfs2(v,val,bob,som,som1+1);
		}
		}
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        adj.clear();
        tout.clear();
        ans=-1e9;
        val=0;
        tin.clear();
        timer=0;
        vis.clear();
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
    dfs(0,1,bob);
    vis.clear();
    amount1=amount;
    dfs2(0,val,bob,0,1);
    return ans;
    }
};
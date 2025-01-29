class Solution {
public:
   map<int,vector<int>>adj;
   map<int,bool>vis;
   map<pair<int,int>,bool>vis2;
   bool test=false;
   void dfs(int u){
    if(test==true)return;
    
	if(vis[u]==1){test=true;return;}
	vis[u]=1;
    
    for(auto v:adj[u]){
    if(vis2[make_pair(u,v)]!=1){vis2[make_pair(v,u)]=1;vis2[make_pair(u,v)]=1;
	dfs(v);}}
	}
   
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        test=false;
        vis2.clear();
        vis.clear();
        adj.clear();
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);

        }
        vector<int>res;
        dfs(1);
        
        for(auto v:edges){
           
                if((vis[v[0]]==1)and(vis[v[1]]==1)and(adj[v[0]].size()>=2)and(adj[v[1]].size()>=2)){
                    if(!res.empty())res.clear();
                    res.push_back(v[0]);
                    res.push_back(v[1]);
                   
                   

                }
            
        }
        for(auto v:vis)cout<<v.first<<endl;
        
        return res;
        
            }
};
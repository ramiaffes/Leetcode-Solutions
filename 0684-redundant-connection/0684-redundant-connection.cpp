class Solution {
public:
   map<int,vector<int>>adj;
   map<int,bool>vis;
   int val=0;
   map<pair<int,int>,bool>vis2;
   bool test=false;
   vector<pair<int,int>>res;
   void dfs(int u){
    if(test==true)return;
    
	if(vis[u]==1){val=u;test=true;return;}
	vis[u]=1;
    
    for(auto v:adj[u]){
    if(vis2[make_pair(u,v)]!=1){vis2[make_pair(v,u)]=1;vis2[make_pair(u,v)]=1;res.push_back(make_pair(u,v));
	dfs(v);}}
	}
   
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        test=false;
         val=0;
        res.clear();
        vis2.clear();
        vis.clear();
        adj.clear();
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);

        }
        
        dfs(1);
        map<pair<int,int>,bool>vis3;
        int val3=val;
        for(int i=res.size()-1;i>=0;i--){
            if(res[i].second==val){
                vis3[res[i]]=1;
                val=res[i].first;
                if(val==val3)break;
            }

        }vector<int>res2;
        for(auto v:edges){
            if(vis3[make_pair(v[0],v[1])])res2= v;
            if(vis3[make_pair(v[1],v[0])])res2= v;
        }
        
        
        
        return res2;
        
            }
};
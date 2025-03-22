class Solution {
public:
    map<int,vector<int>>adj;
    vector<int>res;
    map<int,bool>vis;
    void dfs(int u){
        vis[u]=1;
        res.push_back(u);
        for(auto v:adj[u]){
            if(vis[v]==1){continue;}
            dfs(v);
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        map<pair<int,int>,bool>vis2;
        vis.clear();
        res.clear();
        adj.clear();
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            vis2[make_pair(edges[i][0],edges[i][1])]=1;
            vis2[make_pair(edges[i][1],edges[i][0])]=1;
        }
    int som=0;
    bool test=true;
    for(int i=0;i<(n);i++){
       
        if(vis[i]==0){dfs(i);
        test=true;
        for(int i=0;i<res.size();i++){
            if(test==false)break;
            for(int j=i+1;j<res.size();j++){
                if(vis2[make_pair(res[i],res[j])]==0){test=false;break;}
            }
        }
        if(test==true)som++;

        res.clear();}
    }
    return som;
    }
};
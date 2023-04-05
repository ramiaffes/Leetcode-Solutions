
map<string,set< string>>adj;
map< string,bool>vis;
map<pair<string,string>,double>hashing;
map<string,string>parent;
double val=-1;
void dfs( string u,double p,string target){ 
    if(parent[u]!="")
    p*=hashing[make_pair(parent[u],u)];
    if(u==target){val=p;return ;  }
    if(vis[u])return;
	vis[u]=1;
 
	for(auto v:adj[u]){
       
        parent[v]=u;
		 dfs(v,p,target);
		}

	}
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double>answers(queries.size());
        hashing.clear();
        vis.clear();
        adj.clear();
       map<string,bool>vis1;
        for(int i=0;i<equations.size();i++){
            adj[equations[i][0]].insert(equations[i][1]);
            adj[equations[i][1]].insert(equations[i][0]);
            vis1[equations[i][0]]=1;
            vis1[equations[i][1]]=1;
            hashing[make_pair(equations[i][0],equations[i][1])]=values[i];
            hashing[make_pair(equations[i][1],equations[i][0])]=1/values[i];
        }
    for(int i=0;i<queries.size();i++){
        val=-1; parent.clear();vis.clear();
        if(vis1[queries[i][0]]==0)answers[i]=-1;
       else{dfs(queries[i][0],1,queries[i][1]);
       answers[i]=val;}
    }
    
    return answers;
        
    }
};
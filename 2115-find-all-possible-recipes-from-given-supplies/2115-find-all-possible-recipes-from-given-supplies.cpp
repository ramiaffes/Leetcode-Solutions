class Solution {
public:
    map<string,bool>vis;
    map<string,bool>vis1;
    map<string,vector<string>>adj;
    bool test=true;
    void dfs(string u){
        if(test==false)return;
        if(vis[u])return;
        if((adj[u].empty())and(vis1[u]==0)){test=false;return;}
        for(auto v:adj[u]){
            dfs(v);
        }
    }

    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        
        for(int i=0;i<recipes.size();i++){
            for(auto v:ingredients[i]){
                adj[recipes[i]].push_back(v);
            }

        }
    for(int i=0;i<supplies.size();i++){
        vis1[supplies[i]]=1;
    }
    vector<string>res;
    for(int i=0;i<recipes.size();i++){
        test=true;
        dfs(recipes[i]);
        if(test==true){res.push_back(recipes[i]);}
    }
    return res;

    }
};
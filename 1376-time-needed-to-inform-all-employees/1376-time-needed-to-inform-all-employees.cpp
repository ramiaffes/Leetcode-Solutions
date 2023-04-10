
class Solution {
public:

int ans=0;
    map<int,vector<int>>adj;
    vector<int>informTime1;
void dfs(int u,int som){
    som+=informTime1[u];
    ans=max(ans,som);
    for(auto v:adj[u]){dfs(v,som);}
}
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        ans=0;
        adj.clear();
        informTime1.resize( informTime.size());
        informTime1=informTime;
        for(int i=0;i<manager.size();i++){
            if(i!=headID)
            adj[manager[i]].push_back(i);
        }
    dfs(headID,0);
    return ans;
    
    }
};
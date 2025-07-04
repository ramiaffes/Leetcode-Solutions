map<int,vector<int>>adj;
vector<int>res;
void dfs(int u,int val,bool test,int n){
    if(test==true)return;
    if(res.size()==n)return;
    val=val*10+u;
    if(val<=n)res.push_back(val);
    else{test=true;}
    for(auto v:adj[u])dfs(v,val,test,n);
}
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        res.clear();
        adj.clear();
        for(int i=0;i<=9;i++){
            for(int j=0;j<=9;j++){
                adj[i].push_back(j);
            }
        }
    for(int i=1;i<=9;i++){
        dfs(i,0,false,n);
    }
    return res;
    }
};
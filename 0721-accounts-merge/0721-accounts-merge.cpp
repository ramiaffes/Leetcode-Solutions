map<string,string> parent;
void make_set(string v) {
    parent[v] = v;
}
 
string find_set(string v) {
    if (v == parent[v])
        return v;
    return find_set(parent[v]);
}
 
void union_sets(string a, string  b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b)
        parent[b] = a;
}
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string,string>hashing;
        map<string,bool>vis;
        parent.clear();
        vector<vector<string>>res;
        map<string,vector<string>>res1;
        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
            make_set(accounts[i][j]);
                hashing[accounts[i][j]]=accounts[i][0];
        }}
    for(int i=0;i<(accounts.size());i++){
        for(int j=1;j<(accounts[i].size()-1);j++){
        union_sets(accounts[i][j],accounts[i][j+1]);}}
    for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                if(vis[accounts[i][j]]==0)
               res1[find_set(accounts[i][j])].push_back(accounts[i][j]);
                vis[accounts[i][j]]=1;;
            }}
    for(auto v:res1){
        vector<string>res2=v.second;
        sort(res2.begin(),res2.end());
        res2.insert(res2.begin(),hashing[v.first]);
        res.push_back(res2);
        
    }
    return res;
    
    
    
    
    
    }
};
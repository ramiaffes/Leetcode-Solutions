map<int,set<int>>adj; map<int,int>hashing;
int som=0;
bool issquare(int n){
    int i=0;
    while(i*i<n){
        i++;
    }
    if((i*i)==n)return true;
    return false;
    
}
void dfs(int u,int val,map<int,int>hashing1){
    hashing1[u]++;  
    if(hashing1[u]==(hashing[u]+1))return;
    else if(hashing1[u]==(hashing[u]))val++;
    if(val==hashing.size()){
        som++;
        return ;
    }
    for(auto v:adj[u])dfs(v,val,hashing1);
}
class Solution {
public:
    int numSquarefulPerms(vector<int>& nums) {
        adj.clear();
        hashing.clear();
        som=0;
        for(int i=0;i<(nums.size()-1);i++){
            for(int j=i+1;j<nums.size();j++){
            if(issquare(nums[i]+nums[j])){
            adj[nums[i]].insert(nums[j]);
            adj[nums[j]].insert(nums[i]);}}
        }
   for(int i=0;i<nums.size();i++){
       hashing[nums[i]]++;
   }
        map<int,int>hashing1;
    for(auto v:hashing){
        dfs(v.first,0,hashing1);
       
        
    }
        
    return som;
    
    }
};
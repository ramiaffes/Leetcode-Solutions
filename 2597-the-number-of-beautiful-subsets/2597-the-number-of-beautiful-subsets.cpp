class Solution {
public:
    int power(int p,int n){
        int v=1;
        for(int i=0;i<n;i++){
            v*=p;
        }
    return v;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        map<int,int>adj;
        map<int,bool>vis;
        map<int,int>hashing;
        for(int i=0;i<nums.size();i++){
            vis[nums[i]]=1;
            hashing[nums[i]]++;
            if(vis[nums[i]-k]==1){
                adj[nums[i]-k]=nums[i];
            }
        }
     vis.clear();
    vector<vector<int>>vect1;
     for(int i=0;i<nums.size();i++){
         int v=nums[i];
         vector<int>vect;
         if(vis[v]==1)continue;
         while(v!=0){
             vect.push_back(v);
             vis[v]=1;
             v=adj[v];
         }
        vect1.push_back(vect);
     }
    vector<int>res(vect1.size());
    for(int i=0;i<vect1.size();i++){
        vector<int>dp(vect1[i].size());
        for(int j=0;j<vect1[i].size();j++){
            for(int j1=0;j1<(j-1);j1++){
                dp[j]+=dp[j1]*(power(2,hashing[vect1[i][j]])-1);
            }
        dp[j]+=(power(2,hashing[vect1[i][j]])-1);
        
        }
    int som=0;
    for(auto v:dp){
        som+=v;
    }
    res[i]=som;
    
    
    }
int p=1;
for(auto v:res){
    p*=(v+1);
}
        p--;
return p;
    
    

    
    
    
    
    
    
            }
};
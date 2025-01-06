class Solution {
public:
    map<int,int>hashing;
    map<int,int>hashing2; 
    map<int,bool>vis;
    map<int,vector<int>>adj;
    int res=-1e9;
    
    int maxNonOverlapping(vector<int>& nums, int target) {
    int som=0;
    res=0;
    adj.clear();
    hashing.clear();
    hashing2.clear();
    vis.clear();
    map<int,bool>vis3;
    for(int i=0;i<nums.size();i++){
            som+=nums[i];
            if(vis[som-target]==1){
                vis3[i]=1;
            if(i>(hashing[som-target]))
            hashing2[i]=hashing[som-target]+1;}
            vis[som]=1;
            if(som==target){
                vis3[i]=1;
                hashing2[i]=max(hashing2[i],0);
            }
            hashing[som]=i;
        }
        vis.clear();
        vector<int>vect;
   
        for(auto v:hashing2){
            vis[v.second]=1;
        }
        map<int,int>hashing4;
        for(auto v:hashing2){
            hashing4[v.second]=1e9;
        }
        for(auto v:hashing2){
            hashing4[v.second]=min(v.first,hashing4[v.second]);
        }
        map<int,int>hashing3;
        int var=-1;
        for(int i=0;i<nums.size();i++){
            if((vis[i])and(var!=-1)){
            hashing3[var]= i;
            }
            if(vis3[i]){var=i;}
            
        }
        var=-1;
        for(int i=nums.size()-1;i>=0;i--){
            if((vis3[i])and(hashing3[i]==0)){hashing3[i]=hashing3[var];}
            if(vis3[i])var=i;
            
        }
        
        map<int,int>dp;
        if(nums[nums.size()-1]==target){dp[nums.size()-1]=1;}
        for(int i=nums.size()-2;i>=0;i--){
            dp[i]=max(dp[i],dp[i+1]);
            if((hashing4[i]!=0)or((i==0)and(nums[i]==target))){
            dp[i]=max(dp[i],dp[hashing3[hashing4[i]]]+1);
            }
            
            
            
            
            
        }
        for(auto v:dp){res=max(res,v.second);}




    

    

    
    return res;
    }
};
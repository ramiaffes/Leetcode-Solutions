class Solution {
public:
    map<int,int>dp;
    map<int,bool>vis;
    map<int,int>hashing;
    void func(int i,vector<int>vect){
            dp[i]=hashing[vect[i]]*vect[i];
            vis[i]=1;
            int n=vect.size();
            if((i<(n-1))and(vect[i+1]==vect[i]+1)){
                if(i<(n-2)){
                if(vis[i+2]==0){
                func(i+2,vect); }
                dp[i]=max(dp[i],dp[i+2]+hashing[vect[i]]*vect[i]);}
                if(i<(n-3)){
                if((vis[i+3]==0)and(vect[i+3]==vect[i+2]+1)){
                func(i+3,vect);}
                    dp[i]=max(dp[i],dp[i+3]+hashing[vect[i]]*vect[i]);
                }
            
            }
        else if(i<(vect.size()-1)){
            if(i<(vect.size()-1)){
                if(vis[i+1]==0){
                func(i+1,vect); }
                dp[i]=max(dp[i],dp[i+1]+hashing[vect[i]]*vect[i]);}
                if(i<(vect.size()-2)){
                if((vis[i+2]==0)and(vect[i+2]==vect[i+1]+1)){
                func(i+2,vect);}
                    dp[i]=max(dp[i],dp[i+2]+hashing[vect[i]]*vect[i]);
                }
        }
        }
    int deleteAndEarn(vector<int>& nums) {
       dp.clear();
       vis.clear();
       hashing.clear();
        for(int i=0;i<nums.size();i++){
            hashing[nums[i]]++;
        }
        vector<int>vect;
        for(auto v:hashing){
            vect.push_back(v.first);
        }
       
        func(0,vect); if(vect.size()==1)return dp[0];
        func(1,vect);
        return max(dp[0],dp[1]);
        
    
    }
};
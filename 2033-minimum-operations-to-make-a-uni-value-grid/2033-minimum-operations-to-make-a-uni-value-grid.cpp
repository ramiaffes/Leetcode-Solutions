class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        map<int,int>vis;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                vis[grid[i][j]]++;
            }
        }
        vector<int>res;
        for(auto v:vis){
            res.push_back(v.first);
        }
        int som=0;
        vector<int>dp(res.size());
        for(int i=0;i<(res.size()-1);i++){
            if((res[i+1]-res[i])%x!=0)return -1;
            som+=vis[res[i]];
            dp[i+1]=dp[i]+((res[i+1]-res[i])/x)*som;
        }
        vector<int>dp1(res.size());
        som=0;
        for(int i=(res.size()-2);i>=0;i--){
            if((res[i+1]-res[i])%x!=0)return -1;
            som+=vis[res[i+1]];
            dp1[i]=dp1[i+1]+((res[i+1]-res[i])/x)*som;
        }
        int minimum=1e9;
    
        for(int i=0;i<(res.size());i++){
            
            minimum=min(minimum,dp[i]+dp1[i]);
        }
        if(minimum==1e9)return 0;
        return minimum;
        
    
    


    }
};
class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>>res(ages.size());
        int som=0;
        for(int i=0;i<res.size();i++){
            res[i].first=ages[i];
            res[i].second=scores[i];
        }
        sort(res.begin(),res.end());
        stack<int>st;
        stack<int> temp;
        vector<int>dp(ages.size());
        for(int i=0;i<ages.size();i++){
            dp[i]=res[i].second;
            for(int j=0;j<i;j++){
                if(res[j].second<=res[i].second)
                dp[i]=max(dp[i],dp[j]+res[i].second);
            }
        
        }
        
    
    for(auto v:dp){
        som=max(v,som);
    }
    return som;
    
    
        
    }
};
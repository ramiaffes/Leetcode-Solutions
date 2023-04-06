class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        vector<int>res1(events.size());
        int ans=0;
        vector<int>dp1(events.size());
        for(int i=0;i<res1.size();i++){
            res1[i]=events[i][0];
        }
    dp1[events.size()-1]=events[events.size()-1][2];
    for(int i=events.size()-2;i>=0;i--){
        dp1[i]=max(dp1[i+1],events[i][2]);
        
    }
        for(int i=0;i<events.size();i++){
            auto it=upper_bound(res1.begin(),res1.end(),events[i][1]);
            if(it==res1.end()){
                ans=max(ans,events[i][2]);continue;
            }
        ans=max(ans,dp1[it-res1.begin()]+events[i][2]);
        }
        return ans;
     
        
        
        
    
    }
};
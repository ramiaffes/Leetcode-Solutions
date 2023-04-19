class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        vector<int>dp(answerKey.length());
        int ans=1;
        dp[0]=(answerKey[0]=='T');
        for(int i=1;i<dp.size();i++){
            dp[i]=dp[i-1];
            if(answerKey[i]=='T'){
                dp[i]++;
            }
        }
    for(int i=0;i<dp.size();i++){
        if(dp[i]<=k){
            
            ans=max(ans,i+1);
        }
        else{
        auto it=lower_bound(dp.begin(),dp.begin()+i,dp[i]-k);
        if(it==(dp.begin()+i)){
            continue;
        }
    int val=it-dp.begin();
    ans=max(ans,i-(val));    }  
    }
    dp.clear();
    dp.resize(answerKey.length());
        dp[0]=(answerKey[0]=='F');
     for(int i=1;i<dp.size();i++){
            dp[i]=dp[i-1];
            if(answerKey[i]=='F'){
                dp[i]++;
            }
        }
    for(int i=0;i<dp.size();i++){
        if(dp[i]<=k){
            
            ans=max(ans,i+1);
        }
        else{
        auto it=lower_bound(dp.begin(),dp.begin()+i,dp[i]-k);
        if(it==(dp.begin()+i)){
            continue;
        }
    int val=it-dp.begin();
    ans=max(ans,i-(val));    }  
    }
    return ans;
    
    
    }
};
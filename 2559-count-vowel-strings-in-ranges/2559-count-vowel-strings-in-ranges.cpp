class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int>dp(words.size());
        string s1="aeiou";
        dp[0]+=(s1.find(words[0][0])!=string::npos)and(s1.find(words[0].back())!=string::npos);
        for(int i=1;i<dp.size();i++){
            dp[i]=dp[i-1];
            dp[i]+=(s1.find(words[i][0])!=string::npos)and(s1.find(words[i].back())!=string::npos);
        }
        vector<int>res(queries.size());
    for(int i=0;i<queries.size();i++){
        if(queries[i][0]>=1)
        res[i]=dp[queries[i][1]]-dp[queries[i][0]-1];
        else res[i]=dp[queries[i][1]];
    }
        return res;
    }
};
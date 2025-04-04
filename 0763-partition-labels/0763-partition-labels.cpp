class Solution {
public:
    vector<int> partitionLabels(string s) {
        bool test=true;
        int val=0;
        int som=0;
        vector<int>res;
        map<char,int>hashing;
        map<char,int>vis;
        map<int,int>valeur;
        for(int i=0;i<s.length();i++){
            hashing[s[i]]++;
        }
        for(auto v:hashing){
            valeur[hashing[v.first]]++;
        }
        for(int i=0;i<s.length();i++){
            if(vis[s[i]]==0){
                som++;
            }
            vis[s[i]]=1;
            valeur[hashing[s[i]]]--;
            hashing[s[i]]--;
            valeur[hashing[s[i]]]++;
        if(valeur[0]==som){
            res.push_back(i-val+1);
            val=i+1;
        }
        }
    return res;
    }
};
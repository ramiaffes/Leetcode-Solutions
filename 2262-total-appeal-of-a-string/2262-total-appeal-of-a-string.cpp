long long int func(long long int n){
    return (n*(n+1))/2;
}
class Solution {
public:
    long long appealSum(string s) {
      long long int som=0;
        int n=s.length();
        map<char,vector<int>>hashing;
        for(int i=0;i<s.length();i++){
            hashing[s[i]].push_back(i);
        }
    for(auto v:hashing){som+=func(n);
        for(int i=0;i<(hashing[v.first].size()-1);i++){
        som-=func(hashing[v.first][i+1]-hashing[v.first][i]-1);
}
som-=func(hashing[v.first][0]);
som-=func(s.length()-hashing[v.first][hashing[v.first].size()-1]-1);
       
    }
return som;
    
        
    
    
    }
};
class Solution {
public:
    int uniqueLetterString(string s) {
        int som=0;
        map<char,vector<int>>hashing;
        for(int i=0;i<s.length();i++){
            hashing[s[i]].push_back(i);
        }
    for(auto v:hashing){
        if(hashing[v.first].size()==1){som+=(hashing[v.first][0]+1)*(s.length()-hashing[v.first][0]);continue;}
        for(int i=1;i<(hashing[v.first].size()-1);i++){
            som+=(hashing[v.first][i+1]-hashing[v.first][i])*(hashing[v.first][i]-hashing[v.first][i-1]);
            
        }
    som+=(hashing[v.first][0]+1)*(hashing[v.first][1]-hashing[v.first][0]);
    som+=(s.length()-hashing[v.first][hashing[v.first].size()-1])*(hashing[v.first][hashing[v.first].size()-1]-hashing[v.first][hashing[v.first].size()-2]);
    }
    return som;
    }
};
class Solution {
public:
    string customSortString(string order, string s) {
        string str;
        map<char,int>hashing;
        for(int i=0;i<s.length();i++){
            hashing[s[i]]++;
        }
        for(int i=0;i<order.length();i++){
            for(int j=0;j<hashing[order[i]];j++){
                str.append(1,order[i]);
                
            }hashing[order[i]]=0;
        }
    for(auto v:hashing){
        for(int i=0;i<hashing[v.first];i++){
            str.append(1,v.first);
        }
    }
    return str;
    }
};
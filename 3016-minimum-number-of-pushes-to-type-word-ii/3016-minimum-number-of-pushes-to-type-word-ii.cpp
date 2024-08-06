class Solution {
public:
    int minimumPushes(string word) {
        map<char,int>hashing;
        int res=0;
        for(int i=0;i<word.length();i++){
            hashing[word[i]]++;
        }
    vector<pair<int,int>>vect;
    for(auto v:hashing){
        vect.push_back(make_pair(v.second,v.first));
    }
    sort(vect.begin(),vect.end());
    reverse(vect.begin(),vect.end());
    int som=0;
    for(auto v:vect){
        res+=hashing[v.second]*(som/8+1);
        som++;  }
    return res;
    }
};
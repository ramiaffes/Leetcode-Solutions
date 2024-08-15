class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int j1=0;
        int res=0;
        map<string,int>hashing;
        for(int i=0;i<words.size();i++){
            hashing[words[i]]++;
        }
        sort(words.begin(),words.end());
        auto ip = unique(words.begin(),words.end());
        words.resize(distance(words.begin(), ip));
        for(int i=0;i<words.size();i++){
            j1=0;
            for(int j=0;j<s.length();j++){
                
                if(s[j]==words[i][j1]){
                    j1++;
                }
            if(j1==(words[i].size())){res+=hashing[words[i]];break;}
            
            }
        }
    return res;
    }
};
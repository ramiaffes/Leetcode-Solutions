class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int>hashing;
        map<char,int>hashing1;
        vector<pair<int,int>>res;
        int som=0;
        for(int i=0;i<t.length();i++){
            hashing[t[i]]++;
        }
    int val=hashing.size();
    int j=0;
    for(int i=0;i<s.length();i++){if(hashing1[s[i]]==hashing[s[i]]-1){som++;}
        hashing1[s[i]]++; 
        if(som<val){
            continue;
       }
       while((j<=i)and(hashing1[s[j]]>hashing[s[j]])){
           hashing1[s[j]]--;
           j++;
       }
     res.push_back(make_pair(i,j));
                                  
    
                          
    }
    int ans=1e9;
    for(auto v:res){
        ans=min(ans,v.first-v.second);
    }
    for(auto v:res){
        if(ans==(v.first-v.second))
            return s.substr(v.second,v.first-v.second+1);
    }
    return "";
    }
};
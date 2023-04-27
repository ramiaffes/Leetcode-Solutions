class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
            vector<int>res2;

                if(s.length()<(words.size()*words[0].length()))return res2;

        int val=words[0].length();
        map<string,int>vis2;
        vector<int>vect(s.length());
        map<int,int>hashing;
        int val10=1;
        for(int i=0;i<words.size();i++){
            if(vis2[words[i]]==0){
            vis2[words[i]]=val10;
            val10++;}
        }
        for(int i=0;i<words.size();i++){
           hashing[vis2[words[i]]]++;
        }
        string str1=s.substr(0,val);
        vector<int>vect1(hashing.size());
        for(auto v:hashing){
            vect1[v.first-1]=v.second;
        }

        for(int i=0;i<s.length();i++){
        if(vis2[str1]!=0){
            vect[i]=vis2[str1];
        }

            if((i+val)<s.length()){
                string var(1,s[i+val]);
            str1.append(var);
            }
            else break;
            str1.erase(0,1);
        }
    vector<vector<int>>res(val);
    for(int i=0;i<val;i++){
        for(int j=0;j<(vect.size()/val);j++){
        res[i].push_back(vect[j*val+i]);}
    }
    
    int val1=0;
    map<int,int>hashing1;
    for(int i=0;i<res.size();i++){
        
         for(int j=0;j<words.size();j++){
             if(res[i][j]!=0){
             if(hashing1[res[i][j]]==(vect1[res[i][j]-1]-1)){
                 val1++;
             }
             else if(hashing1[res[i][j]]==(vect1[res[i][j]-1])){
                 val1--;
             }}
             hashing1[res[i][j]]++;
         }
        for(int d=0;d<res[i].size();d++){
            if(val1==hashing.size()){
                 res2.push_back(i+d*val);
            }
        if(res[i][d]!=0){
        if(hashing1[res[i][d]]==(vect1[res[i][d]-1])){
            val1--;
        }
        else if(hashing1[res[i][d]]==(vect1[res[i][d]-1]+1)){
            val1++;
        } }
        hashing1[res[i][d]]--;
        if(((d+words.size())<res[i].size())){
        if(res[i][d+words.size()]!=0){
         if(hashing1[res[i][d+words.size()]]==(vect1[res[i][d+words.size()]-1]-1)){
                 val1++;
             }
             else if(hashing1[res[i][d+words.size()]]==(vect1[res[i][d+words.size()]-1])){
                 val1--;
             }}
        hashing1[res[i][d+words.size()]]++;}
        
        
        }
        
    }
    

    
        return res2;
    }
};
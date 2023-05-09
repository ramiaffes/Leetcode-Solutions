class Solution {
public:
    bool closeStrings(string word1, string word2) {
        map<char,int>hashing1;
        map<char,int>hashing2;
        for(int i=0;i<word1.length();i++){
            hashing1[word1[i]]++;
        }
          for(int i=0;i<word2.length();i++){
            hashing2[word2[i]]++;
        }
    for(auto v:hashing1){
        if(hashing2[v.first]==0)return false;
    }
     for(auto v:hashing2){
        if(hashing1[v.first]==0)return false;
    }
        vector<int>res1;
        vector<int>res2;
    for(int i=0;i<26;i++){
        res1.push_back(hashing1[i+97]);
    }
         for(int i=0;i<26;i++){
        res2.push_back(hashing2[i+97]);
    }
        sort(res2.begin(),res2.end());
        sort(res1.begin(),res1.end());
        return res2==res1;
    }
};
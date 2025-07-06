class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int>res(word.length());
        res[0]=(word[0]-'0')%m;
        for(int i=1;i<word.length();i++){
            res[i]=(res[i-1]*10+(word[i]-'0'))%m;
        }
    for(int i=0;i<res.size();i++){
        res[i]=(res[i]==0);
    }
    return res;
    }
};
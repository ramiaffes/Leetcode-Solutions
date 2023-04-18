class Solution {
public:
    bool isItPossible(string word1, string word2) {
        map<char,int>hashing1;
        map<char,int>hashing2;
        for(int i=0;i<word1.length();i++){
            hashing1[word1[i]]++;
        }
        for(int i=0;i<word2.length();i++){
            hashing2[word2[i]]++;}
        int som1=hashing1.size();
        int som2=hashing2.size();
        int som3=hashing1.size();
        int som4=hashing2.size();
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                if((hashing1[i+97]==0)or(hashing2[j+97]==0))continue;
                if(i==j){
                    if(som1==som2)return true;continue;
                }
                som3=som1;
                som4=som2;
                if(hashing1[i+97]==1){
                    som3--;
                }
                if(hashing2[i+97]==0){
                    som4++;
                }
                if(hashing2[j+97]==1){
                    som4--;
                }
                 if(hashing1[j+97]==0){
                    som3++;
                }
            if(som3==som4)return true;
                
            }
        }
    
       return false; 
    
    }
};
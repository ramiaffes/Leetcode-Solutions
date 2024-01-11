class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int j=1;
        int i=0;
        int som=0;
        int ans=1;
        while(j<s.length()){
            if(s[j]==s[j-1]){
                som++;
            }
            if(som>=2){
                while((i<=j)and(som>=2)){
                    if(s[i]==s[i+1]){
                        som--;
                    }
                    i++;
                }
            }
            else{
                ans=max(ans,j-i+1);
            }
        j++;
            
        }
    return ans;
    }
};
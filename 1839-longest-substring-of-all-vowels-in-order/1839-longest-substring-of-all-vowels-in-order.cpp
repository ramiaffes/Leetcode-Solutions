class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int j=0;
        int i=0;
        int val=0;
        int ans=0;
        string s=word;
        while(j<s.length()){
            if((s[j]=='a')and(val>1)){
               i=j;
               val=1;

            }
            else if((s[j]=='a')and(val<=1)){
                val=1;
            }
            else if((s[j]=='e')and((val>2)or(val==0))){
                i=j+1;
                val=0;
            }
            else if(s[j]=='e'){
                val=2;
            }
             else if((s[j]=='i')and((val>3)or(val<2))){
                i=j+1;
                 val=0;
            }
            else if(s[j]=='i'){
                val=3;
            }
             else if((s[j]=='o')and((val>4)or(val<3))){
                i=j+1;
                 val=0;
            }
            else if(s[j]=='o'){
                val=4;
            }
             else if((s[j]=='u')and(val<4)){
                i=j+1;
                 val=0;
            }
            else if(s[j]=='u'){
                ans=max(ans,j-i+1);
                val=5;
            }
            else if(val==5){
                ans=max(ans,j-i+1);
            }
        j++;
        }
    return ans;
    }
};
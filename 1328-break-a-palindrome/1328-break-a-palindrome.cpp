class Solution {
public:
    string breakPalindrome(string palindrome) {
        if(palindrome.length()==1)return "";
        int n=palindrome.length();
        int i=0;
        if(palindrome.length()%2==1){
            while((i<(n/2))and(palindrome[i]=='a')){
                i++;
            }
        if(i==(n/2)){
            palindrome[n-1]='b';
        }
            else palindrome[i]='a';
            
        }
        else{
              while((i<=(n/2))and(palindrome[i]=='a')){
                i++;
            }
        if((i>(n/2))){
            palindrome[n-1]='b';
        }
        else palindrome[i]='a';
        }
    return palindrome;
    }
};
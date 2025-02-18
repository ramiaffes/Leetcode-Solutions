class Solution {
public:
    string smallestNumber(string pattern) {
        string str="123456789";
        string str1=str;
        reverse(str1.begin(),str1.end());
        string ans(pattern.length()+1,'9');
        bool test=true;
            for(int i=0;i<pattern.length();i++){
                if(pattern[i]=='I'){
                    if((str[i]-'0')>=(str[i+1]-'0')){
                        test=false;break;
                    }
                }
                else{
                    if((str[i]-'0')<=(str[i+1]-'0')){
                        test=false;break;
                    }
                }
            }
        if(test==true){
            ans=min(ans,str.substr(0,pattern.length()+1));
            
        }
        while(next_permutation(str.begin(),str.end())){
            bool test=true;
            for(int i=0;i<pattern.length();i++){
                if(pattern[i]=='I'){
                    if((str[i]-'0')>=(str[i+1]-'0')){
                        test=false;break;
                    }
                }
                else{
                    if((str[i]-'0')<=(str[i+1]-'0')){
                        test=false;break;
                    }
                }
            }
        if(test==true){
            ans=min(ans,str.substr(0,pattern.length()+1));
            
        }
        }
    return ans;
    }
};
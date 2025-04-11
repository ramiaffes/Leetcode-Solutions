class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int res=0;
        for(int i=low;i<=high;i++){
            string str=to_string(i);
            int val1=0;
            int val2=0;
            if(str.length()%2==1)continue;
            for(int i=0;i<str.length()/2;i++){
                val1+=str[i]-'0';
            }
            for(int i=str.length()/2;i<str.length();i++){
                val2+=str[i]-'0';
            }
        if(val1==val2)res++;


        }
    return res;
    }
};
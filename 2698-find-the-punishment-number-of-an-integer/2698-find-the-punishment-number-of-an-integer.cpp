class Solution {
public:
    bool check(string str,int d,int j,int res){
        string res1;
        bool test=false;
        if(j==str.length()){
            
            if(res==d)return true;
            else return false;
        }
        for(int i=j;i<str.length();i++){
            res1+=str[i];
            test=test or check(str,d,i+1,res+stoi(res1));
            if(test==true)break;




        }
        return test;


    }
    int punishmentNumber(int n) {
        int res=0;
        for(int i=1;i<=n;i++){
            string str=to_string(i*i);
            
            if (check(str,i,0,0)){res+=i*i;}
        }
    return res;
    }
};
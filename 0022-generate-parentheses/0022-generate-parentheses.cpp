class Solution {
public:
    vector<string>res1;
    void func(string res,int n1,int n2,int n){
        if((n1==n)and(n2==n)){
            res1.push_back(res);
            return ;
        }
        else{
            if(n2<n1){
                func(res+')',n1,n2+1,n);
            }
            if(n1<n){
                func(res+'(',n1+1,n2,n);
            }
            
            
        }
        
    }
    vector<string> generateParenthesis(int n) {
        res1.clear();
        string res="";
        func(res,0,0,n);
        return res1;
    }
};
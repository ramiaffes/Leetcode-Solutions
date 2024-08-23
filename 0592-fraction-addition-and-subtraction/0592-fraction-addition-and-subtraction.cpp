class Solution {
public:
    int gcd(int a, int b) 
{ 
    if (a == 0) 
        return b; 
    if (b == 0) 
        return a; 
  
    
    if (a == b) 
        return a; 
  
    
    if (a > b) 
        return gcd(a - b, b); 
    return gcd(a, b - a); 
} 
    string fractionAddition(string expression) {
        vector<int>num;
        vector<int>denom;
        for(int i=0;i<expression.length();i++){
            if(expression[i]=='/'){
                if((i>1)and(expression[i-2]=='-')){
                    num.push_back(-(expression[i-1]-'0'));
                }
                else if((i>1)and(expression[i-2]=='1')){
                    if((i>2)and(expression[i-3]=='-')){
                    num.push_back(-10);
                }
                else num.push_back(10);
                }
                else num.push_back((expression[i-1]-'0'));
                if((i<(expression.length()-2))and(expression[i+2]=='0')){
                    denom.push_back(10);
                }
            else
                denom.push_back((expression[i+1]-'0'));
            }
        }
    int p=1;
    for(auto v:denom){
        p*=v;
    }
    for(int i=0;i<num.size();i++){
        num[i]*=(p/denom[i]);
    }
    int p2=0;
    for(auto v:num){
        p2+=v;
    }
    int val=0;
    if(p2<0){
        val=gcd(p,-p2);
    }
    else val=gcd(p,p2);
    p=p/val;
    p2=p2/val;
    return  to_string(p2)+"/"+to_string(p);
    
    
    }
};
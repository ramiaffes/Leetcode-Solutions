class Solution {
public:
    int minimumLength(string s) {
        int som=1; int val=s.length();
        vector<int>res;
        for(int i=1;i<s.length();i++){
            if(s[i]==s[i-1]){
                som++;
            }
            else{
                res.push_back(som);
                som=1;
            }
        }
    res.push_back(som);
    auto ip = unique(s.begin(), s.end());
   
    s.resize(distance(s.begin(), ip));
    int i=0;
    int j=s.length()-1;
   
    while(i<j){
    
        if(s[i]==s[j]){
            
            val-=res[i];
            val-=res[j];
            i++;
            j--;
        }
        else{
            break;
        }
    }
    if(i==j){
        if(res[i]==1)return 1;
        return 0;
    }
    return val;
    }
};
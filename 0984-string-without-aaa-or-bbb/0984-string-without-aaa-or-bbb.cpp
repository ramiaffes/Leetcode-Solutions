class Solution {
public:
    string strWithout3a3b(int a, int b) {
        int a1=a;
        int b1=b;
        int test=0;
        vector<int>res2;
        vector<int>res1;
        while((a>0)and(b>0)){
            if(a>=b){
            if(test==0){
            res1.push_back(1);a--;
            if(a==0)break;}
            else {res2.push_back(1);b--;
                 if(b==0)break;}
            test=1-test;}
            else{
                if(test==0){
            res2.push_back(1);b--;
            if(b==0)break;}
            else {res1.push_back(1);a--;
                 if(a==0)break;}
            test=1-test;
            }
        
            
        }
    if(a>=3){
        for(int i=0;i<res1.size();i++){
            res1[i]++;
            a--;
            if(a<3)break;
        }
    
       }
    
        if(b>=3){
        for(int i=0;i<res2.size();i++){
            res2[i]++;
            b--;
            if(b<3)break;
        }
   }
        if(a>0)res1.push_back(a);
        if(b>0){res2.push_back(b);}
    int i=0;
    int j=0;
    string str;
    if(a1>=b1){
        int test1=0;
        while((i<res1.size())or(j<res2.size())){
        if(test1==0){
            string val(res1[i],'a');
            str.append(val);
            i++;
        }
    else{
        string val(res2[j],'b');
            str.append(val);
            j++;
    }
        test1=1-test1;
    }}
    else{
          int test1=0;
        while((i<res1.size())or(j<res2.size())){
        if(test1==1){
            string val(res1[i],'a');
            str.append(val);
            i++;
        }
    else{
        string val(res2[j],'b');
            str.append(val);
            j++;
    }
        test1=1-test1;
    }
    }
        return str;
    
    }
};
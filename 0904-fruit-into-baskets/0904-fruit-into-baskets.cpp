class Solution {
public:
    int totalFruit(vector<int>& fruits) { 
        int i=0;
        int j=0;
        int res=0;
        map<int,int>hashing;
        int val1=fruits[0];
        int val2=-1;
        while(i<fruits.size()){
            while(j<fruits.size()){
            
            if((val2==-1)and(val1==-1)){
                val1=fruits[j];
            }
            else if((val2==-1)and(val1!=fruits[j])){ 
                val2=fruits[j];
            }
            else if((val1==-1)and(val2!=fruits[j])){val1=fruits[j];}
            else if(val2!=-1){
                if((fruits[j]!=val2)and(fruits[j]!=val1)){
                    break;

                }
                
            } 
            hashing[fruits[j]]++;
            j++;
            


        }
        res=max(res,j-i);
        
       
        if(hashing[fruits[i]]==1){if(val1==fruits[i])val1=-1; else if(val2==fruits[i])val2=-1;}
        hashing[fruits[i]]--;
        i++;
         }
        
return res;
    }
};
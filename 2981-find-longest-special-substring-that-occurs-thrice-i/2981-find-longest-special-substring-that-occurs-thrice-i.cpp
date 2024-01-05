class Solution {
public:
    int maximumLength(string s) {
        int i=0;
        int j=0;
        int ans1=-1;
        map<pair<char,int>,int>hashing;
        map<char,int>hashing2;
        while(j<s.length()){
            if(s[j]!=s[i]){
                i=j;
            }
            hashing[make_pair(s[j],(j-i+1))]+=1;
            hashing2[s[j]]=max(hashing2[s[j]],j-i+1);
            j++;
        }
    
    for(auto v:hashing2){
        int val=v.second;
        int val2=0;
        while((val>=1)and(val2<3)){
            val2+=hashing[make_pair(v.first,val)];
            if(val2>=3){
                ans1=max(ans1,val);
            }
            val--;
            
        }
    }
    
    

        
        
     
    return ans1;
    
        
    }
};
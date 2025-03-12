class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        int j=0;
        int i=0;
        int som=0;
        map<int,int>vis;
        long long int res=0;
        map<int,int>hashing;
        int som1=0;
        while(j<word.length()){
            if((word[j]!='a')and(word[j]!='e')and(word[j]!='i')and(word[j]!='u')and(word[j]!='o')){som++;hashing[j]=som1;som1=0;}
        else{vis[word[j]]+=1;hashing[j]=som1;som1+=1;}
        if((som==k)and(vis['a']>=1)and(vis['e']>=1)and(vis['i']>=1)and(vis['u']>=1)and(vis['o']>=1)){
            while(vis[word[i]]>1){vis[word[i]]--;i++;}
            res+=(hashing[i]+1);
            j++;
           continue;
        }
        
     else if(som<=k){
        j++;continue;
     }
     else{
        while((som>k)and(i<=j)){
            if(vis[word[i]]>=1){vis[word[i]]--;}
            else som--;
                i++;
        }
        if(i>j){j++;continue;}
        
        if((som==k)and(vis['a']>=1)and(vis['e']>=1)and(vis['i']>=1)and(vis['u']>=1)and(vis['o']>=1)){
            while(vis[word[i]]>1){vis[word[i]]--;i++;}
            res+=(hashing[i]+1);
            
     }
     j++;continue;
     
      
    
        }
   
    }
    
    
    
  return res;}
};
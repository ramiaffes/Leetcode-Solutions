class Solution {
public:
    string robotWithString(string s) {
        map<char,int>hashing;
        string res;
        for(int i=0;i<s.length();i++){
            hashing[s[i]]++;
        }
        int c=0;
        stack<char>st;
        for(int i=0;i<s.length();i++){
            
            while((c<26)and(hashing[c+97]==0)){
                c++;
            }
             if((!st.empty())and(st.top()<=(c+97))){
                
                while((!st.empty())and(st.top()<=(c+97))){
                res+=st.top();
                st.pop();
                }

                hashing[s[i]]--;
                st.push(s[i]);
            }
           else if(s[i]==(c+97)){
                hashing[c+97]--;
                res+=s[i];
            }
            
            else {hashing[s[i]]--;st.push(s[i]);}

        }
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        
        
        return res;
    }
};
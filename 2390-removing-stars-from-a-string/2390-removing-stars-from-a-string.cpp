class Solution {
public:
    string removeStars(string s) {
        stack<char>st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='*'){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
    string s1;
    while(not(st.empty())){
        string val(1,st.top());
        s1.append(val);
        st.pop();
    }
        reverse(s1.begin(),s1.end());
    return s1;
    }
};
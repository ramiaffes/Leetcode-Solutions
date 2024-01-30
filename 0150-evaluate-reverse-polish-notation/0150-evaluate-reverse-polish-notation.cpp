class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+"){
           int som=0;
           som+=st.top();
           st.pop();
           som+=st.top();
           st.pop();
           st.push(som);
            }
            else if(tokens[i]=="-"){
           int som=0;
           som-=(int)st.top();
           st.pop();
           som+=(int)st.top();
           st.pop();
           st.push(som);
            }
        else if(tokens[i]=="*"){
           int som=1;
           som*=st.top();
           st.pop();
           som*=st.top();
           st.pop();
            st.push(som);
            }
        else if(tokens[i]=="/"){
           int som=1;
           int val2=st.top();
           st.pop();
           int val1=st.top();
           som=val1/val2;
           st.pop();
           st.push(som);
            }
    else{
        st.push(stoi(tokens[i]));
    }
    
        
            
        }
    return st.top();
    }
};
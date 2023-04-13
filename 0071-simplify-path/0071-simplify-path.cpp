class Solution {
public:
    vector<string> out;
    void tokenize( string s,const char delim)
{
    size_t start;
    size_t end = 0;
 
    while ((start = s.find_first_not_of(delim, end)) != string::npos)
    {
        end = s.find(delim, start);
        out.push_back(s.substr(start, end - start));
    }
}
    string simplifyPath(string path) {
        out.clear();
        tokenize(path,'/');
        stack<string>st;
        string res;
        for(auto v:out){
            if((v=="."))continue;
            if(v==".."){if(not(st.empty()))st.pop();}
            else st.push(v);
            
        }if(st.empty())res.insert(0,"/");
    while(not(st.empty())){
      
        res.insert(0,st.top());  res.insert(0,"/");
        st.pop();
    }
        
    return res;
    }
};
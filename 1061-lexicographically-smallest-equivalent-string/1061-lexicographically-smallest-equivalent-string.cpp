map<char,bool>vis;
map<char,char> parent;
void make_set(char  v) {
    parent[v] = v;
}
 
char find_set(char v) {
    if (v == parent[v])
        return v;
    return(find_set(parent[v]));
}
 
void union_sets(char a, char b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b){
        parent[b] = a;
    }
    
}
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        parent.clear();
        map<char,char>minim;
         for(int i=0;i<26;i++){
             make_set(i+97);
             minim[i+97]=i+97;
         }
        for(int i=0;i<s1.length();i++){
            union_sets(s1[i],s2[i]);
        }
    
    for(int i=0;i<s1.length();i++){
        minim[find_set(s1[i])]=min(minim[find_set(s1[i])],s1[i]);
    }
    for(int i=0;i<s2.length();i++){
        minim[find_set(s2[i])]=min(minim[find_set(s2[i])],s2[i]);
    }
string res;
for(int i=0;i<baseStr.length();i++){
    string val(1,minim[find_set(baseStr[i])]);
    res.append(val);
}
return res;

    }
};
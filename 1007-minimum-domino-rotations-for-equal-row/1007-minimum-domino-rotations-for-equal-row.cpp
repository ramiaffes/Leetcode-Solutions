class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        map<int,int>hashing;
        for(int i=0;i<tops.size();i++){
            if(tops[i]==bottoms[i]) hashing[tops[i]]++;
            else{
            hashing[tops[i]]++;
            hashing[bottoms[i]]++;}
        }
    int ans=1e9;
    int som1=0;
    int som2=0;
    for(auto v:hashing){
        if(hashing[v.first]==tops.size()){
             for(int i=0;i<tops.size();i++){
                if(tops[i]==v.first)som1++;
                else som2++;
             }
        ans=min(ans,som1);
        ans=min(ans,som2);
        som1=0;
        som2=0;
        }
    }
    if(ans==1e9)return -1;
    return ans;
    
    }
};
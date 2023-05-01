map<int,int>hashing;
vector<int>vect;
vector<vector<int>>res;
void func(int i,int target,int som,vector<int>res1){
    if((som==target)and(i==vect.size())){
        res.push_back(res1);
        return;
    }
    else if((som>target)or(i==vect.size())){
        return;
    }
    for(int j=0;j<=hashing[vect[i]];j++){
    som+=vect[i]*j;
        res1.push_back(j);
    func(i+1,target,som,res1);
    res1.erase(i+res1.begin());
    som-=vect[i]*j;}
    
}
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        hashing.clear();
        vect.clear();
        res.clear();
        for(int i=0;i<candidates.size();i++){
            hashing[candidates[i]]++;
        }
        for(auto v:hashing){
            vect.push_back(v.first);
        }
        vector<int>res1;
    func(0,target,0,res1);
    vector<vector<int>>resf;
    for(int i=0;i<res.size();i++){
        vector<int>vect1;
        for(int j=0;j<res[i].size();j++){
            for(int i1=0;i1<res[i][j];i1++){
                vect1.push_back(vect[j]);
            }
        }
    resf.push_back(vect1);
    }
    return resf;
    
    
    }
};
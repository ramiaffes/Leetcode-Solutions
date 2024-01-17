class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int>vis;
        for(int i=0;i<arr.size();i++){
            vis[arr[i]]+=1;
        }
    set<int>se;
    for(auto v:vis){
        se.insert(v.second);
    }
        return (se.size()==vis.size());
    }
};
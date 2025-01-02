class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        map<int,int>hashing;
         map<int,int>hashing2;
        for(int i=0;i<target.size();i++){
            hashing[target[i]]++;
        }
        for(int i=0;i<arr.size();i++){
            hashing2[arr[i]]++;
        }
    for(auto v:hashing){
        if(hashing[v.first]!=hashing2[v.first])return false;
    }
    return true;
    }
};
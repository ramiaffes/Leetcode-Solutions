class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int>hashing;
        vector<int>res;
        int val=0;
        int som=0;
        for(int i=0;i<arr.size();i++){
            hashing[arr[i]]++;
        }
    for(auto v:hashing){
        res.push_back(v.second);
    }
        sort(res.begin(),res.end());
    
        while((val<res.size())and(som<k)){
            som+=res[val];
            val++;
        }
       if(som>k)val--;
    return(hashing.size()-val);
    }
};
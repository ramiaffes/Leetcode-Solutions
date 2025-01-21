class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        map<long long int,int>hashing;
        long long int k1=k;
        for(int i=0;i<arr.size();i++){
         hashing[(arr[i]+1000000000*k1)%k1]++;
        }
        if(hashing[0]%2==1)return false;
        for(int i=1;i<k;i++){
            if(hashing[i]!=hashing[k-i])return false;
        }
        return true;
    }
};
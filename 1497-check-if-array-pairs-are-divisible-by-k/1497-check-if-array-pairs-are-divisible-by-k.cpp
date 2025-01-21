class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        map<int,int>hashing;
        for(int i=0;i<arr.size();i++){
            hashing[arr[i]%k]++;
        }
        if(hashing[0]%2==1)return false;
        for(int i=1;i<k;i++){
            if(hashing[i]!=hashing[k-i])return false;
        }
        return true;
    }
};
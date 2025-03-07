class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
     bool prime[1000001];
    memset(prime, true, sizeof(prime));
    prime[1]=false;
    for (int p = 2; p * p <= right; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= right; i += p)
                prime[i] = false;
        }
    }
    int val=-1;
    map<int,vector<int>>hashing;
    for(int i=left;i<=right;i++){
        if(prime[i]){
            if(val!=-1){
                if(hashing[i-val].empty()) {hashing[i-val].push_back(val);hashing[i-val].push_back(i);}
            }
            val=i;

        }

    }
    for(auto v:hashing) return v.second;
    vector<int>vect;
    vect.push_back(-1);
    vect.push_back(-1);
    return vect;
    }
};
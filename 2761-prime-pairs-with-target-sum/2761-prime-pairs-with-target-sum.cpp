class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
      bool prime[1000000];
    memset(prime, true, sizeof(prime));
    prime[1]=false;
    for (long long int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (long long int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    vector<vector<int>>res;
    for(int i=2;i<n;i++){
        if(prime[i]==true){
        vector<int>vect2;
        vect2.push_back(n-i);
        vect2.push_back(i);
            if((prime[n-i]==true)and((n-i)<=i))res.push_back(vect2);
            

        }
    
    }
    reverse(res.begin(),res.end());
return res;
    }
};
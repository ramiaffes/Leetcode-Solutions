class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int som=0;
        vector<int>C(A.size());
        map<int,int>hashing;
        for(int i=0;i<A.size();i++){
            hashing[A[i]]++;
            if(hashing[A[i]]==2)som++;
            hashing[B[i]]++;
            if(hashing[B[i]]==2)som++;
            C[i]=som;
            
            
        }
    return C;
    }
};
class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        map<int,int>hashing;
        map<int,int>hashing1;
        map<int,int>hashing2;
        vector<int>answers(queries.size());
        for(int i=0;i<queries.size();i++){
            if(hashing1[hashing[queries[i][1]]]!=0)
            hashing1[hashing[queries[i][1]]]--;
            hashing[queries[i][1]]++;
            hashing1[hashing[queries[i][1]]]++;
            if(hashing2[queries[i][0]]!=0){
            if(hashing1[hashing[hashing2[queries[i][0]]]]!=0)
            hashing1[hashing[hashing2[queries[i][0]]]]--;
            hashing[hashing2[queries[i][0]]]--;
            hashing1[hashing[hashing2[queries[i][0]]]]++;}
            hashing2[queries[i][0]]=queries[i][1];
            answers[i]=hashing.size()-hashing1[0];



        }
    return answers;
    }
};
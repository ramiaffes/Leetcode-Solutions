class Solution {
public:
    int minimumDeletions(string word, int k) {
        map<char,int>hashing;
        for(int i=0;i<word.size();i++){
            hashing[word[i]]++;
        }
        vector<int>values;
        for(auto v:hashing){
            values.push_back(v.second);
        }
     sort(values.begin(),values.end());
     vector<int>vect(values.size());
     for(int i=0;i<(values.size()-1);i++){
        for(int j=i+1;j<values.size();j++){
            if(values[j]>(values[i]+k)){
                vect[i]+=values[j]-values[i]-k;
            }
        }

     }
     int som=0;
     int i=0;
        while((i<values.size())and(values[i]<vect[i])){
            som+=values[i];
            i++;
        }
    if(i<values.size()){som+=vect[i];}
    return som;
    
    }
};
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int som=0;
        map<long long int,long long int>hashing;
        for(int i=0;i<answers.size();i++){
            hashing[answers[i]]++;
            
        }
        for(auto v:hashing){
            if((v.first+1)>=hashing[v.first])
            som+=((v.first+1));
            else if(hashing[v.first]%(v.first+1)==0){
               som+=(hashing[v.first]); 
            }
            else{
                som+=(((hashing[v.first])/(v.first+1))+1)*(v.first+1);
            }
        }
    return som;
    }
};
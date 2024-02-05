class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        deque<int>res;
        if(arr.size()==1){res.push_back(arr[0]);vector<int> myVector(res.begin(), res.end());return myVector;}
        map<int,int>hashing;
        for(int i=0;i<arr.size();i++){
            hashing[arr[i]]++;
        }
        auto it1 =unique (arr.begin(), arr.end());   
        arr.resize(distance(arr.begin(),it1) );
        auto it=upper_bound(arr.begin(),arr.end(),x);
        int val1=it-arr.begin()-1;
        int val2=val1+1;
        int som=0;
        while((val1>=0)or(val2<arr.size())){
            if(val1<0){
                for(int i=0;i<min(hashing[arr[val2]],k-som);i++){
                res.push_back(arr[val2]);}
                som+=hashing[arr[val2]];
                val2++;
            }
            else if(val2>=arr.size()){
                for(int i=0;i<min(hashing[arr[val1]],k-som);i++){
                res.push_front(arr[val1]);}
                som+=hashing[arr[val1]];
                val1--;
            }
            else if((x-arr[val1])>(arr[val2]-x)){
                
                for(int i=0;i<min(hashing[arr[val2]],k-som);i++){
                res.push_back(arr[val2]);}
                som+=hashing[arr[val2]];
                val2++;
            }
            else if ((x-arr[val1])==(arr[val2]-x)){
                for(int i=0;i<min(hashing[arr[val1]],k-som);i++){
                res.push_front(arr[val1]);}
                som+=min(hashing[arr[val1]],k-som);
                val1--;
            }
            else {for(int i=0;i<min(hashing[arr[val1]],k-som);i++){
                res.push_front(arr[val1]);}
                som+=min(hashing[arr[val1]],k-som);val1--;}
            if(som==k)break;
        }
    vector<int> myVector(res.begin(), res.end());
    return myVector;
        
    }
};
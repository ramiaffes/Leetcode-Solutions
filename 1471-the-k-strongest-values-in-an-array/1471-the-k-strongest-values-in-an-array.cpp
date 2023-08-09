class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        int j=arr.size()-1;
        int i=0;
        sort(arr.begin(),arr.end());
        int m=0;
            m=arr[(arr.size()-1)/2]*2;
        
        int som=0;
        vector<int>res;
        while(i<j){
            if(som==k){
                break;
            }
            if((m-2*arr[i])>(2*arr[j]-m)){
                res.push_back(arr[i]);
                som++;
                i++;
                continue;
            }
          else if((m-2*arr[i])<(2*arr[j]-m)){
               res.push_back(arr[j]);
                som++;
                j--;
                continue;
          }
        else{
            
            res.push_back(arr[j]);
            som++;
           j--;
        }
    
        }if((i==j)and(som!=k))res.push_back(arr[i]);
    
    return res;
    }
};
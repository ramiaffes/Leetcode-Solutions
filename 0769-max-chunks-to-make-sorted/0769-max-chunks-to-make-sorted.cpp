class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        map<int,bool>vis2;
        map<int,bool>vis1;
        int som=0;
        for(int i=0;i<arr.size();i++){
            vis1[arr[i]]=1;
            if((arr[i]==0)or(vis2[arr[i]-1]==1)){
                vis2[arr[i]]=1;
            }
        int val=arr[i]+1;
        while(val<arr.size()){
          if((vis1[val]==1)and(vis2[val-1]==1)){
              vis2[val]=1;
              
          }val++;}
           if(vis2[i]==1){
               som++;
           }
            
        }
    
    return som;
    }
};
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int i=0;
        int j=i+1;
        int ans=arr.size()-1;
        map<int,bool>vis;
        vis[arr.size()-1]=1;
        for(int i=arr.size()-2;i>=0;i--){
            if(arr[i]<=arr[i+1])
            vis[i]=vis[i+1];
            else vis[i]=0;
        }
        while(i<arr.size()){
        if(j==i){
            j=i+1;
        }
        while((j<arr.size())and((arr[i]>arr[j])or(vis[j]==0))){
            j++;
            
        }

    
    ans=min(ans,j-i-1);
    if(j==arr.size())break;
    if(arr[i]>arr[i+1])break;i++;}
    int ans2=0;
    int ans3=arr.size()-1;
    while((ans2<(arr.size()-1))and(arr[ans2]<=arr[ans2+1])){
        ans2++;
    }   
    while((ans3>=1)and(arr[ans3]>=arr[ans3-1])){
        ans3--;
    }
 
        int val=arr.size()-ans2-1;
        int val1=ans3;
      return min(min(ans,val1),val);  
    }
};
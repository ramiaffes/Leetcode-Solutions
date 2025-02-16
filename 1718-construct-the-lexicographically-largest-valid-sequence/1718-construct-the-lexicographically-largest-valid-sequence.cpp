class Solution {
public:
    vector<int>res;
    bool test2=false;
    void  func(map<int,bool>vis,map<int,int>vis1,int val,int n){
        bool test=false;
        if(test2)return;
        for(int i=n;i>=1;i--){
            if(vis1[i]==0){
            test=true;
            while(vis[val])val++;
            vis1[i]=val+1;
            vis[val]=1;
            if(i!=1){
            if((val+i)>=(2*n-1)){vis[val]=0;vis1[i]=0;continue;}
            if(vis[val+i]){vis[val]=0;vis1[i]=0;continue;}
            vis[val+i]=1;

           

            } func(vis,vis1,val,n);if(i!=1)vis[val+i]=0;vis[val]=0;vis1[i]=0;
        }
    } if(test==false){
         for(int i=1;i<=n;i++){
            res[vis1[i]-1]=i;
            if(i!=1)
            res[i+vis1[i]-1]=i;
            test2=true;
        }return;
    
    }}
    vector<int> constructDistancedSequence(int n) {
        res.resize(2*n-1);
        test2=false;
        int val=0;
        map<int,int>vis1;
        map<int,bool>vis;
        func(vis,vis1,val,n);
        return res;
    }
};
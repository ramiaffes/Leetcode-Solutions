class Solution {
public:
    bool test=false;
    vector<int> nums1;
    map<int,int>vis;
    void func(int som,int som1,int i1){
        if(test==true)return; 
        if(vis[som1]==0){vis[som1]=1e9;}
       vis[som1]=min(vis[som1],i1+1);
        for(int i=i1+1;i<nums1.size();i++){ 
            som1+=nums1[i];
            if(som1<(som/2)){
                if(((vis[som1]==0)or(vis[som1]>(i+1)))){
                    
                func(som,som1,i);
               
                } 
            }
        else if(som1==(som/2)){
            test=true;return;
        }
            if(vis[som1]==0){vis[som1]=1e9;}
               vis[som1]=min(vis[som1],i+1);
             
            som1-=nums1[i];
            }
        
        
        }
    bool canPartition(vector<int>& nums) {
        test=false;
        nums1=nums;
        int som=0;
       vis.clear();
        for(int i=0;i<nums.size();i++){
            som+=nums[i];
        } 
        sort(nums.begin(),nums.end());
        if(som%2==1)return false;
        func(som,0,-1);
       
        return test;
       
        
        
    }
};
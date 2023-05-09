class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        map<int,bool>vis;
        for(int i=0;i<banned.size();i++)vis[banned[i]]=1;
        int som=0;
        int som1=0;
        for(int i=1;i<=n;i++){
            if (vis[i]) continue;
            som+=i;
            som1++;
            if(som>maxSum)break;
        }
        if(som>maxSum)som1--;
        return som1;
    }
};
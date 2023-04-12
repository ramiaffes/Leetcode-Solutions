class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int val=node1;
        int som=0;
        map<int,int>hashing;
        map<int,bool>vis;
        map<int,bool>vis1;
        while((val!=-1)and(vis1[val]==0)){
            hashing[val]=max(hashing[val],som);
            vis1[val]=1;
            som++;
            val=edges[val];
        }
        val=node2;
        som=0;
         while((val!=-1)and(vis[val]==0)){
            hashing[val]=max(hashing[val],som);
             vis[val]=1;
            som++;
            val=edges[val];
        }
        int ans=1e6;
        for(auto v:hashing){if((vis[v.first])and(vis1[v.first]))ans=min(ans,v.second);}
         for(auto v:hashing){if((ans==v.second)and((vis[v.first])and(vis1[v.first])))return v.first;}
        
            return -1;
    }
};
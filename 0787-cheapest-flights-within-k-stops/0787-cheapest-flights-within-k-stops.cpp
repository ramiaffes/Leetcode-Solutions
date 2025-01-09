class Solution {
public:
 map<int,vector<int>>adj1;
 map<int,vector<int>>adj2;
map<int,bool>vis;
map<int , int> dist1;
map<int , int> dist2;
map<int , int> dist3;
map<pair<int,int>,int>price;
void bfs1(int src){
	dist1[src]=0;
	queue<int>q;
	q.push(src);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto v:adj1[u]){
			if(vis[v])continue;
			dist1[v]=min(dist1[v],(dist1[u]+1));
			q.push(v);}
		}}
    void bfs2(int src){
	dist2[src]=0;
	queue<int>q;
	q.push(src);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto v:adj2[u]){
			if(vis[v])continue;
			dist2[v]=min(dist2[v],(dist2[u]+1));
			q.push(v);}
		}}
    int som=0;
    void bfs3(int src,int k){
	dist3[src]=0;
	queue<int>q;
	q.push(src);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto v:adj1[u]){
			cout<<v<<" "<<dist1[v]<<" "<<dist2[v]<<endl;
            if((dist2[v]+dist1[u])<=k){
			dist3[v]=min(dist3[v],(dist3[u]+price[make_pair(u,v)]));
            cout<<dist3[v]<<endl;q.push(v);}
			}
		}}
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        adj1.clear();
        som=0;
        adj2.clear();
        vis.clear();
        dist1.clear();
        dist2.clear();
        dist3.clear();
        price.clear();
        for(int i=0;i<n;i++){
            dist1[i]=1e9;
            dist2[i]=1e9;
            dist3[i]=1e9;

        }
        for(int i=0;i<flights.size();i++){
            adj1[flights[i][0]].push_back(flights[i][1]);
            adj2[flights[i][1]].push_back(flights[i][0]);
            price[make_pair(flights[i][0],flights[i][1])]=flights[i][2];
        }
        bfs1(src);
        
        vis.clear();
        bfs2(dst);
        vis.clear();
        bfs3(src,k);
        if(dist3[dst]==1e9)return -1;
        return dist3[dst];
    }
};
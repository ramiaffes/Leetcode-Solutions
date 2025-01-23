class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
      int n=grid.size();
    int m=grid[0].size();
    set<pair<int,int>>se;
     set<pair<int,int>>se1;   
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
               se.insert(make_pair(i,j));
            }
            if(se.size()>=2){
                for(auto v:se){
                    se1.insert(v);
                }
            }
        se.clear();
        }for(int j=0;j<m;j++){
          for(int i=0;i<n;i++){
            
                if(grid[i][j]==1)
               se.insert(make_pair(i,j));
            }
            if(se.size()>=2){
                for(auto v:se){
                    se1.insert(v);
                }
            }
        se.clear();
        }
       return  se1.size();
    }
};
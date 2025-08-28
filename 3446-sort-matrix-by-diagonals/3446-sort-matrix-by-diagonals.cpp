class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<=i;j++){
                int i1=i+1;
                int j1=j+1;
                 while((i1<grid.size())and(j1<grid.size())){
                     if(grid[i][j]<grid[i1][j1]){
                         swap(grid[i][j],grid[i1][j1]);
                         
                     }i1++;
                         j1++;
                 }
            }
        }
    for(int i=0;i<grid.size();i++){
            for(int j=i+1;j<grid.size();j++){
                int i1=i+1;
                int j1=j+1;
                 while((i1<grid.size())and(j1<grid.size())){
                     if(grid[i][j]>grid[i1][j1]){
                         swap(grid[i][j],grid[i1][j1]);
                         
                     }i1++;
                         j1++;
                 }
            }
        }
    return grid;
    }
};
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int islandNum = 0;
        for(int i=0; i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == '1'){
                    visit_island(grid,i,j);
                    islandNum++;
                }
            }
        }
        return islandNum;
    }
    void visit_island(vector<vector<char>>& grid, int i, int j){
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size()||grid[i][j]!='1')
            return;
        grid[i][j]='2';
        visit_island(grid, i+1,j);
        visit_island(grid, i-1,j);
        visit_island(grid, i,j+1);
        visit_island(grid, i,j-1);
    }    
};
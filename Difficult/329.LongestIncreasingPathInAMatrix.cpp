class Solution {
public:
    int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<vector<int>> memo;
    int DFSTraverse(vector<vector<int>>& matrix, int i,int j, int R, int C){
        if(memo[i][j] != 0)
            return memo[i][j];
        int ans = 0;
        for(auto &row:dirs){
            int x =i+row[0],y=j+row[1];
            if (0<=x && x<R && 0<=y && y<C && matrix[x][y]>matrix[i][j])
                ans = max(ans,DFSTraverse(matrix,x,y,R,C));
        }
        memo[i][j] = ans+1;
        return memo[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {

        if(matrix.empty()||matrix[0].empty())
            return 0;
        int m=matrix.size();
        int n=matrix[0].size();
        memo = vector<vector<int>>(m,vector<int>(n,0));
        int ans = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                ans = max(ans, DFSTraverse(matrix, i, j, m,n));
        return ans;
    }
};
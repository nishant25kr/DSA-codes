class Solution {
public:
    int f(int i,int j,int sum,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(i==0 && j==0) return grid[0][0];
        if(i<0 || j<0) return 1e9;

        sum+=grid[i][j];

        if(dp[i][j]!= -1) return dp[i][j];

        int up = f(i-1,j,sum,grid,dp);        
        int l = f(i,j-1,sum,grid,dp);        

        return dp[i][j]=grid[i][j] + min(up, l);

    }

    int minPathSum(vector<vector<int>>& grid) {


        int m = grid.size();
        int n = grid[0].size();
        int sum =0;
        vector<vector<int>>dp(m,vector<int>(n,-1));

        return f(m-1,n-1,sum,grid,dp);        
    }
};
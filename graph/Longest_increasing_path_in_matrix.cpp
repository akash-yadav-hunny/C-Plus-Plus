class Solution {
public:
    int solve(int i , int j , vector<vector<int>>& mat , vector<vector<int>>& dp){
        //base 
        int n = mat.size();
        int m = mat[0].size();
        int maxi = 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int dx[4] = {-1, 0 , 1 , 0};
        int dy[4] = {0 , 1 , 0 , -1};
        for(int k=0 ; k<4 ; ++k){
            int nr = i+dx[k];
            int nc = j+dy[k];
            if(nr>=0 && nr<n && nc>=0 && nc<m && mat[nr][nc]>mat[i][j]){
                maxi = max(maxi , 1+solve(nr , nc , mat , dp));
            }
            dp[i][j]=maxi;
        }
        return maxi;
    }
    int longestIncreasingPath(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int maxi = 1;
        vector<vector<int>>dp(n , vector<int>(m , -1));
        for(int i=0 ; i<n ; ++i){
            for(int j=0 ; j<m ; ++j){
                maxi = max(maxi , solve(i,  j , mat , dp));
            }
        }
        return maxi ;
    }
};

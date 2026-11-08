#include<bits/stdc++.h>
using namespace std;

//leecode 62
//we need to find all the unique ways to reach n-1,m-1 form 0,0.
//recursion + memoization solution
int N,M;
int ways(int row,int col,vector<vector<int>>&memo){
    //base case->
    if(row == M-1 && col == N-1){
        return 1;
    }
        
    if(memo[row][col] != -1){
        return memo[row][col];
    }
    int sum = 0;
    //as we can only move right or down.
    if(row+1 < M){
        sum += ways(row+1,col,memo);
    }

    if(col+1 < N){
        sum += ways(row,col+1,memo);
    }

    return memo[row][col] = sum;

}
int uniquePaths(int m, int n) {
    N = n;
    M = m;

    vector<vector<int>> memo(M,vector<int>(N,-1));
    int result = ways(0,0,memo);

    return result;
}
//dp and tabulation.
int uniquePaths_dp(int m, int n) {
    vector<vector<int>> dp(m,vector<int>(n,0));
    dp[0][0] = 1;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            //we will all ways find the sum of left and up for the current grid position.
                
            if(i==0 && j==0){
                continue;
            }

            int sum = 0;
            if(i-1 >= 0){
                sum += dp[i-1][j];
            }
            if(j-1 >= 0){
                sum += dp[i][j-1];
            }

            dp[i][j] = sum;
        }
    }

    return dp[m-1][n-1];
}
//dp and space optimized.
int uniquePaths_optimal(int m, int n) {
    vector<int> prev(n,0);

    for(int i = 0; i < m; i++){
        vector<int> temp(n,0);
        for(int j = 0; j < n; j++){
            if(i==0 && j==0){
                temp[0] = 1;
                continue;
            }
                
            temp[j] = prev[j];
            if(j>0){
                temp[j] += temp[j-1];
            }
        }
        prev = temp;
    }

    return prev[n-1];
}


//leetcode 63 --> similar to last problem only change in one line.
//recursive and memo
int n_obs,m_obs;
int recursivepath(int row,int col,vector<vector<int>>& obstacleGrid,vector<vector<int>>&memo){
    //base case->
    if(obstacleGrid[row][col] == 1){
        return 0;
    }
    if(row == n_obs-1 && col == m_obs-1){
        return 1;
    }
        
    if(memo[row][col]!=-1){
        return memo[row][col];
    }

    int ans =0;
    //down-->
    if(row+1<n_obs){
        ans+= recursivepath(row+1,col,obstacleGrid,memo);
    }
    if(col+1<m_obs){
        ans+= recursivepath(row,col+1,obstacleGrid,memo);
    }
    return memo[row][col] = ans;
}
int uniquePathsWithObstacles_rec(vector<vector<int>>& obstacleGrid) {
    n_obs = obstacleGrid.size();
    m_obs = obstacleGrid[0].size();
    vector<vector<int>>memo(n_obs,vector<int>(m_obs,-1));
    return recursivepath(0,0,obstacleGrid,memo);
}
//dp and tabulation
int uniquePathsWithObstacles_dp(vector<vector<int>>& obstacleGrid) {
    int n = obstacleGrid.size();
    int m = obstacleGrid[0].size();
        
    vector<vector<int>> dp(n,vector<int>(m,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(obstacleGrid[i][j] == 1){
                dp[i][j] = 0;
            }
            else if(i==0 && j==0){
                dp[i][j] = 1;
            }
            else{
                int ans = 0;
                if(i > 0){
                    ans+=dp[i-1][j];
                }
                if(j > 0){
                    ans+=dp[i][j-1];
                }
                dp[i][j] = ans;
            }  
        }
    }
    return dp[n-1][m-1];
}
//dp + space optimized
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int n = obstacleGrid.size();
    int m = obstacleGrid[0].size();
        
    vector<int> prev(m,0);

    for(int i=0;i<n;i++){
        vector<int> temp(m,0);
        for(int j=0;j<m;j++){
            if(obstacleGrid[i][j] == 1){
                prev[j] = 0;
            }
            else if(i==0 && j==0){
                temp[j] = 1;
            }
            else{
                int ans = 0;
                if(i > 0){
                    ans+=prev[j];
                }
                if(j > 0){
                    ans+=temp[j-1];
                }
                temp[j] = ans;
            }  
        }
        prev = temp;
    }
    return prev[m-1];
}







int main(){

}
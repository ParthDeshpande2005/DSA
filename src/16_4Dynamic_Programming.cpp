#include<bits/stdc++.h>
using namespace std;


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
int uniquePaths(int m, int n) {
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




int main(){

}
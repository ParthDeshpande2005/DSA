#include<bits/stdc++.h>
using namespace std;


//problem form sde sheet on takeUForward.
//recursion + memoization.
//we will need 2d memoization for this.
int recursion_ninja(int cur,int pastchoice,vector<vector<int>>& matrix,vector<vector<int>>&memo){
    if(cur >= matrix.size()){
        return 0;
    }
        
    if(pastchoice!= -1 && memo[cur][pastchoice] != -1){
        return memo[cur][pastchoice];
    }

    int result = 0;
    for(int i = 0;i <= 2;i++){
        if(pastchoice == i){
            continue;
        }
        
        result = max(result,matrix[cur][i]+recursion_ninja(cur+1,i,matrix,memo));
    }
    if(pastchoice == -1){
        return result;
    }
    return memo[cur][pastchoice] = result;
}
int ninjaTraining(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> memo(n,vector<int>(3,-1));
    int ans = recursion_ninja(0,-1,matrix,memo);
        
    return ans; 
}
//dp and tabulation solution-->
int ninjaTraining_dp(vector<vector<int>>& matrix) {
    int n = matrix.size();

    vector<vector<int>> dp(n,vector<int>(4,0));
        
    dp[0][0] = max(matrix[0][1],matrix[0][2]);
    dp[0][1] = max(matrix[0][0],matrix[0][2]);
    dp[0][2] = max(matrix[0][0],matrix[0][1]);
    dp[0][3] = max(dp[0][1],dp[0][0]);

    for(int day = 1;day < n;day++){
        for(int last = 0;last <4;last++){
            dp[day][last] = 0;
            int maxi = 0;
            for(int task =0;task<3;task++){
                if(task!=last){
                    int point = matrix[day][task] + dp[day-1][task];
                    maxi = max(maxi,point);
                }
            }
            dp[day][last] = maxi;
        } 
    }
    return dp[n-1][3];
}
//dp + space optimization-->
int ninjaTraining_optimized(vector<vector<int>>& matrix) {
    int n = matrix.size();

    vector<int> prev(4,0);
        
    prev[0] = max(matrix[0][1],matrix[0][2]);
    prev[1] = max(matrix[0][0],matrix[0][2]);
    prev[2] = max(matrix[0][0],matrix[0][1]);
    prev[3] = max(prev[1],prev[0]);

    for(int day = 1;day < n;day++){
        vector<int> temp(4,0);
        for(int last = 0;last <4;last++){
            temp[last] = 0;

            for(int task =0;task<3;task++){
                if(task!=last){
                    temp[last] = max(temp[last],matrix[day][task]+prev[task]);
                }
            }
        } 
        prev = temp;
    }
    return prev[3];
}



int main(){


    return 0;
}
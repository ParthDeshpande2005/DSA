#include<bits/stdc++.h>
using namespace std;


//Subset sum equals to target
//recursion and memoization
//we will directly change the target insted of maintainig the sum so that we can reduce one dimension of the dp.
//IMP-> instead of maintainig the bool memo we can use int memo so that we can maintain the -1,0,1 in same which is more optimal.
//this is easy to maintain and inplement.
int nsubset;
bool recursionsubset(int ind, vector<int> &arr,int target,vector<vector<int>> &memo){
    //base case->
    if(target == 0){
        return true;
    }
    if(target < 0 || ind >= nsubset){ // boundry check
        return false;
    }
    if(memo[ind][target] != -1){
        return memo[ind][target];
    }
        
    //take =>
    bool take = recursionsubset(ind+1,arr,target-arr[ind],memo);
    if(take){ //early return avoid unnecessary status
        return memo[ind][target] = take;
    }

    //pass =>
    bool pass = recursionsubset(ind+1,arr,target,memo);

    return memo[ind][target] = pass;

}
bool isSubsetSum_recursive(vector<int>arr, int target){
    nsubset = arr.size();
    vector<vector<int>> memo(nsubset,vector<int>(target+1,-1));
    return recursionsubset(0,arr,target,memo);
}
//dp and tabulation solution...
bool isSubsetSum_dp(vector<int>arr, int target){
    int n = arr.size();

    //creating dp
    vector<vector<bool>> dp(n,vector<bool>(target+1,false));

    //initilazing
    dp[n-1][0] = true;

    if(arr[n-1] <= target){
        dp[n-1][arr[n-1]] = true;
    }

    for(int i = n-2;i >= 0; i--){
        for(int t = 0; t <= target; t++){
            if(dp[i+1][t] == true){

                if(t == target){
                    return true;
                }

                dp[i][t] = true;

                if(t + arr[i] <= target){
                    dp[i][t + arr[i]] = true;
                }
            }
        }
    }

    return dp[0][target];
}
//space optimized solution-->
bool isSubsetSum_spaceoptimized(vector<int>arr, int target){
    int n = arr.size();

    //creating dp
    vector<bool> dp(target+1,false);

    //initilazing
    dp[0] = true;

    if(arr[n-1] <= target){
        dp[arr[n-1]] = true;
    }

    for(int i = n-2;i >= 0; i--){
        vector<bool> temp(target+1,false);
        for(int t = 0; t <= target; t++){
            if(dp[t] == true){

                if(t == target){
                    return true;
                }

                temp[t] = true;

                if(t + arr[i] <= target){
                    temp[t + arr[i]] = true;
                }
            }
        }
        dp = temp;
    }

    return dp[target];
}







int main(){


    return 0;
}
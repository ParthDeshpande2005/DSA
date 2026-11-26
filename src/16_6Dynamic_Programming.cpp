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


//leetcode 416. Partition Equal Subset Sum..
//recursion and memoization solution..
int N;
int total;
bool recursion(int ind,int sum,vector<int> & nums,vector<vector<int>>& memo){
    if(ind == N){
        return sum == total - sum;
    }
    if(memo[ind][sum] != -1){
        return memo[ind][sum];
    }

    //add to sum
    bool take = recursion(ind+1,sum+nums[ind],nums,memo);
    if(take){
        return memo[ind][sum] = take;
    }

    //by skiping to add in sum we automatically skip the number.
    bool skip = recursion(ind+1,sum,nums,memo);

    return memo[ind][sum] = skip;
}
bool canPartition_recusive(vector<int>& nums) {
    N = nums.size();
    total = accumulate(nums.begin(), nums.end(), 0);
    
    if(total % 2 != 0){
        return false;
    }

    vector<vector<int>> memo(N,vector<int>(20001,-1));

    return recursion(0,0,nums,memo);
}
//optimized memoization-->
bool recursion_optimal(int ind, int target, vector<int>& nums, vector<vector<int>>& memo) {
    if(target == 0) return true;

    if(ind == N) return false;

    if(memo[ind][target] != -1){
        return memo[ind][target];
    }

    bool take = false;

    if(nums[ind] <= target){
        take = recursion_optimal(ind+1, target-nums[ind], nums, memo);
    }

    bool skip = recursion_optimal(ind+1, target, nums, memo);

    return memo[ind][target] = take || skip;
}
bool canPartition_optimalrecursion(vector<int>& nums) {
    N = nums.size();

    int total = accumulate(nums.begin(), nums.end(), 0);

    if(total % 2 != 0) return false;

    int target = total / 2;

    vector<vector<int>> memo(N, vector<int>(target+1, -1));

    return recursion(0, target, nums, memo);
}
//dp + tabulation
bool canPartition_dp(vector<int>& nums) {
    int n = nums.size();

    int total = accumulate(nums.begin(),nums.end(),0);

    if(total % 2 != 0){
        return false;
    }

    int target = total/2;

    //creating dp
    vector<vector<bool>> dp(n+1,vector<bool>(target+1,false));

    //initalize
    dp[n][0] = true;

    for(int ind = n-1; ind >= 0; ind--){
        for(int t = 0; t <= target; t++){
            if(dp[ind+1][t]){
                dp[ind][t] = true;

                //new sum
                int new_sum = t + nums[ind];
                if(new_sum <= target){
                    dp[ind][new_sum] = true;
                }
            }
        }
    }

    return dp[0][target];
}
// space optimized
bool canPartition_space_optimized(vector<int>& nums) {
    int n = nums.size();

    int total = accumulate(nums.begin(),nums.end(),0);

    if(total % 2 != 0){
        return false;
    }

    int target = total/2;

    //creating prev
    vector<bool> prev(target+1,false);

    //initalize
    prev[0] = true;

    for(int ind = n-1; ind >= 0; ind--){
        vector<bool> temp(target+1,false);
        for(int t = 0; t <= target; t++){
            if(prev[t]){
                temp[t] = true;
                
                //new sum
                int new_sum = t + nums[ind];
                if(new_sum <= target){
                    temp[new_sum] = true;
                }
            }
        }
        prev = temp;
    }

    return prev[target];
}


// Partition a set into two subsets with minimym absolute sum difference
// not solved at all --> leetcode 1049.Last Stone Weight 2..



// count subset with sum K
int end1;
int MOD = 1e9 + 7;
int recursion_perfectsum(int ind, int sum,vector<int> & arr,int K,vector<vector<int>>& memo){
    if(ind == end1){
        if(sum == K){
            return 1;
        }
        return 0;
    }

    if(sum > K){
        return 0;
    }

    if(memo[ind][sum] != -1){
        return memo[ind][sum];
    }

    //take -->
    int take = recursion_perfectsum(ind+1,sum+arr[ind],arr,K,memo) % MOD;
        
    //pass -->
    int pass = recursion_perfectsum(ind+1,sum,arr,K,memo) % MOD;

    return memo[ind][sum] = (take + pass) % MOD;
}
int perfectSum(vector<int>&arr, int K){
    end1 = arr.size();
    vector<vector<int>> memo(end1,vector<int>(K+1,-1));
    return recursion_perfectsum(0,0,arr,K,memo);
}   
// dp and space optimization solution pending 









//Count Partitions with given difference..
//lets solve this like we solve the min max dp proble 
//we observe that the S1 = (total + diff)/2 is true for every case.
//so we will only find this s1 using take and pass method.
// S1 - S2 = diff
// S1 + S2 = total
// 2S1 = total + diff
// S1 = (total + diff) / 2
//recursion solution-->
int recursive_count(int n,int ind,int sum,int target,vector<int>& arr,vector<vector<int>> & memo){
    if(ind == n){
        if(sum == target){
            return 1;
        }
        return 0;
    }

    if(sum > target){
        return 0;
    }

    if(memo[ind][sum] != -1){
        return memo[ind][sum];
    }

    // take
    int take = recursive_count(n,ind+1,sum+arr[ind],target,arr,memo) % MOD;

    // skip
    int skip = recursive_count(n,ind+1,sum,target,arr,memo) % MOD;


    return memo[ind][sum] = (take + skip) % MOD;

}
int countPartitions(int n, int diff, vector<int>& arr) {
    int total = accumulate(arr.begin(),arr.end(),0);
    int target = (total + diff) / 2;

    if(total < diff){
        return 0;
    }

    if((total + diff) % 2 != 0) {
        return 0;
    }
        
    vector<vector<int>> memo(n,vector<int>(target+1 , -1));

    return recursive_count(n,0,0,target,arr,memo);
}








int main(){


    return 0;
}
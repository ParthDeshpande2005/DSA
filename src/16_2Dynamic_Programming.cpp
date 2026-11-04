#include<bits/stdc++.h>
using namespace std;



//leetcode 70.Climbing Stairs
//observation--> this is fibonacchi series.
//so we apply the optimal solution to find fibonacchi.
int climbStairs(int n) {
    int prev2 = 0;
    int prev1 = 1;

    for(int i=2;i<=n+1;i++){
        int curi = prev1 + prev2;
        prev2 = prev1;
        prev1 = curi;
    }

    return prev1;
}


//Frog Jump--> This is not the leetcode probelem...it is different.
//My solution-->
int frogJump(vector<int>& heights) {
    int n = heights.size();
    vector<int> dp(n,-1);
    dp[0] = 0;

    for(int i=0;i<n;i++){
        // 1 step
        if(i+1<n){
            int num1 = dp[i]+abs(heights[i]-heights[i+1]);
            if(dp[i+1]==-1){
                dp[i+1] = num1;
            }
            else{
                dp[i+1] = min(dp[i+1],num1);
            }
        }

        // 2 steps
        if(i+2<n){
            int num2 = dp[i]+abs(heights[i]-heights[i+2]);
            if(dp[i+2]==-1){
                dp[i+2] = num2;
            }
            else{
                dp[i+2] = min(dp[i+2],num2);
            }
        }
    }

    return dp[n-1];
}
//striver--> 
//recursive + memo
int FJrecursion(int ind, vector<int>& heights, vector<int>& dp) {
    if(ind == 0) return 0;

    if(dp[ind] != -1) {
        return dp[ind];
    }

    int left = FJrecursion(ind-1, heights, dp)
               + abs(heights[ind] - heights[ind-1]);

    int right = INT_MAX;

    if(ind > 1) {
        right = FJrecursion(ind-2, heights, dp)
                + abs(heights[ind] - heights[ind-2]);
    }

    return dp[ind] = min(left, right);
}
int frogJumprecursive(vector<int>& heights) {
    int nfj = heights.size();

    vector<int> dp(nfj, -1);

    return FJrecursion(nfj-1, heights, dp);
}
//tabulation + dp + bottom up
int frogJumpdp(vector<int>& heights){
    int n = heights.size();
    
    vector<int> dp(n,0);
    dp[0] = 0;
    for(int i=1;i<n;i++){
        int fs = dp[i-1]+abs(heights[i] - heights[i-1]);
        int ss = INT_MAX;
        if(i>1){
            ss = dp[i-2] + abs(heights[i] - heights[i-2]);
        }

        dp[i] = min(fs,ss);
    }
    return dp[n-1];
}
//most optimal --> space optimization
int frogJumpdp_optimal(vector<int>& heights){
    int n = heights.size();
    
    int prev = 0;
    int prev2 = 0;
    for(int i=1;i<n;i++){
        int fs = prev + abs(heights[i] - heights[i-1]);
        int ss = INT_MAX;
        if(i>1){
            ss = prev2 + abs(heights[i] - heights[i-2]);
        }
        
        int curi = min(fs,ss);
        prev2 = prev;
        prev = curi;
        
    }
    return prev;
}


//Frog Jump K steps-->
//striver--> 
//recursive + memo
int FJKrecursion(int ind, vector<int>& heights, vector<int>& dp,int K) {
    if(ind == 0) return 0;

    if(dp[ind] != -1) {
        return dp[ind];
    }

    int ans = INT_MAX;
    for(int i = 1;i<=K;i++){
        if(ind-i >=0){
            ans = min(ans,FJKrecursion(ind-i,heights,dp,K) + abs(heights[ind]-heights[ind-i]));
        }
        else{
            break;
        }
    }

    return dp[ind] = ans;
}
int frogJumprecursive_K(vector<int>& heights,int K) {
    int nfj = heights.size();

    vector<int> dp(nfj, -1);

    return FJKrecursion(nfj-1, heights, dp,K);
}
//tabulation + dp + bottom up
int frogJumpdp_K(vector<int>& heights,int K){
    int n = heights.size();
    
    vector<int> dp(n,0);
    dp[0] = 0;
    for(int i=1;i<n;i++){
        int ans = INT_MAX;
        for(int j = 1;j<=K;j++){
            if(i-j >= 0){
                ans = min(ans,dp[i-j] + abs(heights[i]-heights[i-j]));
            }
            else{
                break;
            }
        }

        dp[i] = ans;
    }
    return dp[n-1];
}
//most optimal --> space optimization
//not needed as we need to take the k size array and update it multiple times.
//we can get the k = n and this will not change our space complexity at all.
//we can use normal dp for this no need for space optimization.


//leetcode 198.House Robber
//Method 1 -> recursion and memoization
int n;
int recursion_rob(int cur,vector<int>& nums,vector<int>& memo){
    if(cur >= n){
        return 0;
    }

    if(memo[cur]!=-1){
        return memo[cur];
    }

    //take 
    int take = nums[cur] + recursion_rob(cur+2,nums,memo); //cur+2 as we can't pick just next element.

    //pass
    int pass = recursion_rob(cur+1,nums,memo);

    return memo[cur]=max(take,pass);
}
int rob(vector<int>& nums) {
    n = nums.size();
    vector<int> memo(n,-1);

    return recursion_rob(0,nums,memo);
}
//dp and tabulation solution
int rob_dp(vector<int>& nums) {
    int n = nums.size();

    vector<int> dp(n,-1);
    dp[0] = nums[0];

    for(int i=1;i<n;i++){
            
        int take = nums[i];
        if(i>1){
            take += dp[i-2];
        }
            
        //pass
        int pass = 0 + dp[i-1];

        dp[i] = max(pass,take);
            
    }

    return dp[n-1];
}
//dp + space optimization
int rob_optimal(vector<int>& nums) {
    int n = nums.size();

    int prev = nums[0];
    int prev2 = 0;

    for(int i=1;i<n;i++){
        //take
        int take = nums[i]+prev2;

        //pass
        int pass = prev;

        prev2 = prev;
        prev = max(take,pass);
    }

    return prev;
}









int main(){


    return 0;
}
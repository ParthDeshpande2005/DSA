#include<bits/stdc++.h>
using namespace std;

//DP on Stocks -->


//leetcode 121.Best time to buy and sell stock
int maxProfit(vector<int>& prices) {
    int n = prices.size();

    int result = 0;
    int mini = prices[0];

    for(int i = 1;i<n;i++){
        int cur_price = prices[i] - mini;
        result = max(result,cur_price);
        mini = min(mini,prices[i]);
    }

    return result;
}


//leetcode 122.Best time to buy and sell stock 2.
//my idea -> i will travel from back of the array and keep track of the maximum. 
//as soon as i find a number smaller than the max. i will add the diff to answer.
//also i will update the max.
//i can also do this by traveling from front and keeping track of the min.
int maxProfit2(vector<int>& prices) {
    int n = prices.size();
    int result = 0;
    int maxi = prices[n-1];
    for(int i = n-1; i >= 0; i--){
        if(prices[i] < maxi){
            result += maxi - prices[i];
            maxi = prices[i];
        }
        else{
            maxi = max(maxi,prices[i]);
        }
    }
    return result;
}
//striver->
//recursion + memoization ->
int f(int ind, int buy, vector<int>& prices,int n,vector<vector<int>>& dp){
    if(ind == n){
        return 0;
    }
    if(dp[ind][buy] != -1){
        return dp[ind][buy];
    }

    int profit = 0;

    if(buy){ //we can buy 
        int take = -prices[ind] + f(ind+1,0,prices,n,dp);
        int skip = 0 + f(ind+1,1,prices,n,dp);
        profit = max(take, skip);
    }
    else{ //we can't buy we can just sell.
        int sell = prices[ind] + f(ind+1,1,prices,n,dp);
        int skipsell = 0 + f(ind+1,0,prices,n,dp);
        profit = max(sell,skipsell);
    }

    return dp[ind][buy] = profit;
}
int maxProfit2_recursive(vector<int>& prices) {
        
    int n = prices.size();
    vector<vector<int>> dp(n,vector<int>(2,-1));
    return f(0,1,prices,n,dp);
}
//dp + tabulation-->
int maxProfit2_dp(vector<int>& prices) {
    int n = prices.size();

    vector<vector<int>> dp(n+1,vector<int>(2,0));

    dp[n][0] = 0;
    dp[n][1] = 0;

    for(int ind = n-1; ind >= 0; ind--){
        for(int buy = 0; buy <= 1; buy++){
            int profit = 0;
            if(buy){ //we can buy 
                int take = -prices[ind] + dp[ind+1][0];
                int skip = 0 + dp[ind+1][1];
                profit =  max(take, skip);
            }
            else{ //we can't buy we can just sell.
                int sell = prices[ind] + dp[ind+1][1];
                int skipsell = 0 + dp[ind+1][0];
                profit = max(sell,skipsell);
            }
            dp[ind][buy] = profit;
        }
    }
    return dp[0][1];
}
//space optimized-->
int maxProfit(vector<int>& prices) {
    int n = prices.size();

    vector<int> ahead(2,0), cur(2,0);

    for(int ind = n-1; ind >= 0; ind--){
        for(int buy = 0; buy <= 1; buy++){
            int profit = 0;
            if(buy){ //we can buy 
                int take = -prices[ind] + ahead[0];
                int skip = 0 + ahead[1];
                profit =  max(take, skip);
            }
            else{ //we can't buy we can just sell.
                int sell = prices[ind] + ahead[1];
                int skipsell = 0 + ahead[0];
                profit = max(sell,skipsell);
            }
            cur[buy] = profit;
        }
        ahead = cur;
    }
    return ahead[1];
}





























//leetcode 714.Best time to buy and sell stock with transaction fee.
//lets use recursion + memoization to solve this problem.
//lets do the thing where i will subtart the stock when i buy it and add when i sell it.
//this will reduce the size of the memoization table.
//this appoarch is way better than keeping the price at which we brought the stock.
vector<vector<int>> memo;
int nfee;
int recursive_profit(int ind,int buy,vector<int>& prices,int fee){
    if(ind >= nfee){
        return 0;
    }

    if(memo[ind][buy] != -1){
        return memo[ind][buy];
    }

    int profit = 0;
    if(buy == 0){ 
        //take-->
        int take = -prices[ind] + recursive_profit(ind+1,1,prices,fee);

        //skip-->
        int skip = recursive_profit(ind+1,0,prices,fee);

        profit = max(take,skip);
    }
    //sell
    else{ //if will apply the fee at the time of sell.
        //take-->
        int take = prices[ind] - fee + recursive_profit(ind+1,0,prices,fee);

        //skip-->
        int skip = recursive_profit(ind+1,1,prices,fee);

        profit = max(take,skip);
    }
    
    return memo[ind][buy] = profit;
}
int maxProfit_fee(vector<int>& prices, int fee) {
    nfee = prices.size();
    memo.resize(nfee+1,vector<int>(2,-1));
    return recursive_profit(0,0,prices,fee);
}
//dp solution->
int maxProfit_dp_fee(vector<int>& prices, int fee) {
    int n = prices.size();

    //creating dp -->
    vector<vector<int>> dp(n+1,vector<int>(2,-1));

    //initializing dp -->
    dp[n][0] = 0;
    dp[n][1] = 0;

    for(int ind = n-1; ind >= 0; ind--){
        for(int buy = 0; buy <= 1; buy++){
            int profit = 0;
            if(buy == 0){ 
                //take-->
                int take = -prices[ind] + dp[ind+1][1];

                //skip-->
                int skip = dp[ind+1][0];

                profit = max(take,skip);
            }
            //sell
            else{ //if will apply the fee at the time of sell.
                //take-->
                int take = prices[ind] - fee + dp[ind+1][0];

                //skip-->
                int skip = dp[ind+1][1];

                profit = max(take,skip);
            }

            dp[ind][buy] = profit;
        }
    }

    //returning ans--> 
    //we return the dp at index = 0 and the buy value set to 0.
    return dp[0][0];
}
//space optimized solution.
int maxProfit_fee_optimal(vector<int>& prices, int fee) {
    int n = prices.size();

    //initializing -->
    int next_skip = 0;
    int next_buy = 0;

    for(int ind = n-1; ind >= 0; ind--){
        for(int buy = 0; buy <= 1; buy++){
            int profit = 0;
            if(buy == 0){ 
                //take-->
                int take = -prices[ind] + next_skip;

                //skip-->
                int skip = next_buy;

                profit = max(take,skip);
                next_buy = profit;
            }
            //sell
            else{ //if will apply the fee at the time of sell.
                //take-->
                int take = prices[ind] - fee + next_buy;

                //skip-->
                int skip = next_skip;


                profit = max(take,skip);
                next_skip = profit;
            }
        }
    }

    //returning ans--> 
    //we return the dp at index = 0 and the buy value set to 0.
    return next_buy;
}





















int main(){


    return 0;
}
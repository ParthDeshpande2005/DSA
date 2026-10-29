#include<bits/stdc++.h>
using namespace std;

//Introduction to dynamic Programming-->

//Memoization(Top-down)
//--> we tend to store the value of subprobelm in some map/table.
//fibonacchi
//TC->O(N)
//SC->O(N)(recursion stack space)+O(N)(array)
//Recursion stack space is the memory allocated in a computer’s call stack to track active, nested function calls when a function invokes itself
int fibo(vector<int>&dp,int n){
    if(dp[n]!=-1){
        return dp[n];
    }
    if(n<=1){
        return n;
    }
    return dp[n] = fibo(dp,n-1)+fibo(dp,n-2);
}
int findfibo(int n){
    vector<int> dp(n+1,-1);
    return fibo(dp,n);
}

//Tabulation(Bottom-Up)
//this is better as we eleminate the need of the recursive stack space.
//TC->O(N)
//SC->O(N)
int findfibodp(int n){
    vector<int> dp(n+1,-1);
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n-1];
}

//we can optimize this solution even more by just using 2 variable as whole array is not required
//most optimal-->
//TC->O(N)
//SC->O(1)
int findfibo_optimal(int n){
    int prev2 = 0;
    int prev1 = 1;

    for(int i=2;i<=n;i++){
        int curi = prev1 + prev2;
        prev2 = prev1;
        prev1 = curi;
    }
    return prev1;

}


int main(){


    return 0;
}
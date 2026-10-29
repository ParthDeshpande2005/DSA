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




int main(){


    return 0;
}
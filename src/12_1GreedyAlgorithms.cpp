#include<bits/stdc++.h>
using namespace std;


//leetcode 445-->
//see all the appoarch to solve this question in the resoure of striver sheet.
// solving this question using dp or recursion+memoization is really intrestig.
// https://takeuforward.org/data-structure/assign-cookies
int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(),g.end());
    sort(s.begin(),s.end());

    int gsize=g.size();
    int ssize=s.size();

    int content=0;
    int i=0;
    int j=0;

    while(i<gsize && j<ssize){
        if(g[i]<=s[j]) {
            content++;
            i++;
            j++;
        }
        else{
            j++;
        }
    }

    return content;

}


// leetcode 860
bool lemonadeChange(vector<int>& bills) {
    int n=bills.size();
    int five=0;
    int ten=0;
    for(int i=0;i<n;i++){
        
        if(bills[i]==5) five++;

        else if(bills[i]==10){
            if(five>=1){
                ten++;
                five--;
            }
            else {
                return false;
            }
        }

        else{
            if(ten>=1 && five>=1){
                ten--;
                five--;
            }
            else if(ten==0 && five>=3){
                five-=3;
            }
            else{
                return false;
            }
        }
    }
    return true;
}


//leetcode 678 VERY IMP..
//very different apporach..
class Solution {
public:
    vector<vector<int>> memo; // this stores the index and all there possibilites.
    bool recursion(int cur,string s,int sum){
        if(sum<0){
            return false;
        }
        if(cur==s.size()){
            if(sum==0) return true;
            return false;
        }
        if(memo[cur][sum]!=-1){
            return memo[cur][sum];
        }

        bool ans=false;

        if(s[cur]=='('){    
            ans= recursion(cur+1,s,sum+1);
        }
        else if(s[cur]==')'){
            ans= recursion(cur+1,s,sum-1);
        }
        // when * we check for all three condition. 
        else{
            // * as ' '   * as '('  * as ')'
            ans=((recursion(cur+1,s,sum)) || (recursion(cur+1,s,sum+1)) || (recursion(cur+1,s,sum-1)));
        }

        return memo[cur][sum]=ans;
    }

    bool checkValidString(string s) {
        //optimal greedy solution --> TC->O(n) S->O(1)
        //we maintain a range of all possible sum value.
        //we dont consider negative in range.
        int maxi=0;
        int mini=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                mini+=1;
                maxi+=1;
            }
            else if(s[i]==')'){
                mini-=1;
                maxi-=1;
            }
            else {
                mini=mini-1;
                maxi=maxi+1;
            }
            if(mini<0) mini=0;
            if(maxi<0) return false;
        }
        return mini==0;

        // // recursion+memoization solution --> TC->O(n^2)  SC->O(n^2).
        // int n=s.size();
        // memo.assign(n+1,vector<int>(n+1,-1));
        // return recursion(0,s,0);
    }
};



//fractional Knapsack-->
bool comp(vector<int> &a,vector<int>&b){
    float afrac= (float)a[0]/a[1];
    float bfrac= (float)b[0]/b[1];

    return afrac>=bfrac;
}
int fractionalknapsack(vector<vector<int>>& arr,int capacity){
    sort(arr.begin(),arr.end(),comp);
    int n=arr.size();
    int ans=0;

    for(int i=0;i<n;i++){
        int val=arr[i][0];
        int size=min(arr[i][1],capacity);

        ans+=((float)val/arr[i][1])*size;

        capacity-=size;
        if(capacity==0) break;
    }
    return ans;

}


int main(){


    vector<int> g = {1, 2, 3};
    vector<int> s = {1, 1};
    cout<<"Content children: "<<findContentChildren(g,s)<<endl;
    cout<<endl;



    vector<int> bills = {5, 5, 5, 10, 20};
    if (lemonadeChange(bills)) cout << "true\n";
    else cout << "false\n";
    cout<<endl;


    Solution obj;
    if (obj.checkValidString("(*))")) cout << "Valid Parenthesis String\n";
    else cout << "Invalid Parenthesis String\n";
    cout<<endl;


    vector<vector<int>> arr={{100,20},{60,10},{100,50},{200,50}};
    int capacity=90;
    cout<< fractionalknapsack(arr,capacity);


    


    return 0;
}
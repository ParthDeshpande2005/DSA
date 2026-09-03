#include<bits/stdc++.h>
using namespace std;

//Hashing-> prestoring,fetching
//we are storing no of occurance of a number in the new array hash 
//used when we are asked to find number of occurances multiple time


int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //Method 1->using hash arr->
    //precompute
    int hash[13]={0};//considering the input in arr is till 12
    for(int i=0;i<n;i++){
        hash[arr[i]] +=1;
    }

    //Method 2-> using map
    //pre compute
    unordered_map<int,int>mpp;//unordered map has better time complexity than map in most of the cases.
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }   


    int q;//q is the number of values you need to find occurances for.
    cin>>q;
    while(q--){
        int number;
        cin>>number;
        //fetch
        cout<<hash[number]<<endl;//method 1
        cout<<mpp[number]<<endl;//method 2 
    }   
    return 0;
}
//this is input ->
/*
5
1 3 2 1 3
5
1
4
2
3
12
*/
#include<bits/stdc++.h>
using namespace std;



int main(){
    // //Method 1 taking input as array
    // int n;
    // cin>>n;
    // char arr[n];
    // int hash[26]={0};
    // for(int i=0;i<n;i++){
    //     cin>>arr[i];
    //     hash[arr[i]-'a'] +=1;//precompute
    // }

    //Method 2-> taking input as a string
    string s;
    cin>>s;

    //Method 3 using map
    //use unordered_map<char,int>mpp;
    //to store the answer in map variable.

    //pre compute
    int hash[26]={0};
    for(int i=0;i<s.size();i++){
        hash[s[i]-'a']++;
    }

    int q;
    cin>>q;
    while(q--){
        char number;
        cin>>number;
        //fetch
        cout<<hash[number-'a']<<endl;
    }

    return 0;
}

//Input for Method 1->
/*
9
a b c d a b e h f 
5
a
g
h
b
c
*/

//Input for Method 2->
/*
abcdabehf 
5
a
g
h
b
c
*/
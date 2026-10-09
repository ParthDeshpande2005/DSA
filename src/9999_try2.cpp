#include<bits/stdc++.h>
using namespace std;

long long findmax(const vector<int> &arr){
    long long total = 1LL * arr.size() * (arr.size() - 1) / 2; //this gives total pairs.
    long long bad = 0;
    unordered_map<int,int> freq;//this is only to check if the number has arrived before.
    for(int i:arr){
        for(int j=i-4;j<=i+4;j++){
            if((j%2+2)%2 == (i%2+2)%2){ //this condition is used to avoid negative values as well.
                //this is checking if both have same even or odd.
                bad+=freq[j]; //
            }
        }
        freq[i]=1;
    }
    return total - bad;
}

int main(){

    int n;
    cin>>n;

    for(int in=0;in<n;in++){
        int num;
        cin>>num;
        vector<int> arr;
        int temp;
        for(int i=0;i<num;i++){
            cin>>temp;
            arr.push_back(temp);
        }

        unordered_map<int,vector<int>> mpp;

        //i will store the starting index of each traid in the mpp

        for(int i=0;i<num-4;i++){
            int sum=arr[i]+arr[i+2]-arr[i+4];
            mpp[sum].push_back(i);
        }

        long long result = 0;
        //now i have all the starting index in sorted order in the mpp
        for(auto it:mpp){
            result+=findmax(it.second);
        }

        cout<<result<<endl;
    }   


    return 0;
}
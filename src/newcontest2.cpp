//Prefix Max->
#include<bits/stdc++.h>
using namespace std;

void prefixmax(int que[],int n){
        int maxi=que[0];
        for(int i=0;i<n;i++){
            if(maxi<que[i]) maxi=max(maxi,que[i]);
        }
        cout<< n*maxi<<endl;
    }

int main(){
    int cnt;
    cin>>cnt;
    for(int i=0;i<cnt;i++){
        int num;
        cin>>num;
        int arr[num];
        for(int i=0;i<num;i++){
            cin>>arr[i];
        } 
        prefixmax(arr,num);
    }
    return 0;
}
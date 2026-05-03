#include<bits/stdc++.h>
using namespace std;

int TablewithNumber(vector<int> arr,int n,int h,int l){
    int maxi=max(h,l);
    int mini=min(h,l);
    int maxcount=0;
    int mincount=0;
    for(int i=0;i<n;i++){
        if(arr[i]<=maxi){
            if(arr[i]<=mini){
                
                mincount +=1;
            }
            else{
                maxcount +=1;
            }
        }
    }
    int ans=min(mincount,maxcount);
    if(ans==0 && mincount>=2) return mincount/2;
    return ans;
}

int main(){
    int testno;
    cin>>testno;
    for(int i=0;i<testno;i++){
        int n,h,l;
        cin>>n;
        cin>>h;
        cin>>l;
        vector<int> arr;
        for(int j=0;j<n;j++){
            int temp;
            cin>>temp;
            arr.push_back(temp);   
        }
        int ans= TablewithNumber(arr,n,h,l);
        cout<<ans<<endl;
    }
    return 0;
}
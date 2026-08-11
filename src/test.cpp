#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int cur;
        cin>>cur;
        string ans="YES";
        long long sum=0;
        for(int i=1;i<=cur;i++){
            int num;
            cin>>num;
            sum=sum+num;
            sum=sum-i;
            if(sum<0){
                ans="NO";
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
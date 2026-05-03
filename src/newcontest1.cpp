//Perfect Root
#include<bits/stdc++.h>
using namespace std;

void perfectroot(int que){
        for(int j=1;j<=que;j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }

int main(){
    int cnt;
    cin>>cnt;
    int arr[cnt];
    for(int i=0;i<cnt;i++){
        cin>>arr[i];
        perfectroot(arr[i]);
    }
    return 0;
}
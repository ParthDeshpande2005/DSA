#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        vector<int> arr;
        for(int j=0;j<temp;j++){
            int it;
            cin>>it;
            arr.push_back(it);
        }
        int l=0;
        int r=1;
        int ans=1;
        int change=0;
        while(r<temp){
            if(arr[r]==arr[r-1]){
                if(r+1<temp && arr[r+1]!=arr[r]){
                    change+=1;
                }
                else if(r-1>=0 && arr[r-1]!=arr[r]){
                    change+=1;
                }
                else l=r;
            }
            while(change>1){
                if(arr[l]==arr[r]) change-=1;
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        cout<<ans<<endl;
    }
    return 0;
}

















// #include<bits/stdc++.h>
// using namespace std;


// int main(){
//     int n;
//     cin>>n;

//     for(int i=0;i<n;i++){
//         int a,b,c;
//         cin>>a>>b>>c;
//         int count=0;
//         while(a!=b && a!=c && b!=c){
//             //c is greatest
//             if(c>a && c>b){
//                 if(b<a){
//                     c-=1;
//                     b+=1;
//                 }
//                 else{
//                     c-=1;
//                     a+=1;
//                 }
//             }
//             else if(b>a && b>c){
//                 if(c<a){
//                     b-=1;
//                     c+=1;
//                 }
//                 else{
//                     b-=1;
//                     a+=1;
//                 }
//             }
//             else{
//                 if(c<b){
//                     a-=1;
//                     c+=1;
//                 }
//                 else{
//                     a-=1;
//                     b+=1;
//                 }
//             }
//             count+=1;
//         }
//         cout<<count<<endl;
//     }

//     return 0;
// }
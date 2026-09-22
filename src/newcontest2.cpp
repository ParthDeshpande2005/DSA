//Prefix Max->
#include<bits/stdc++.h>
using namespace std;



int main(){
    int cnt;
    cin>>cnt;
    for(int i=0;i<cnt;i++){
        int len;
        cin>>len;
        string str;
        cin>>str;
        
        int cntzero=0;
        for(int j=0;j<len;j++){
            if(str[j]=='0'){
                cntzero++;
            }
        }
        int temp=cntzero;

        int result=INT_MAX;
        int cnt=0;
        for(int k=0;k<len;k++){
            if(str[k]=='0'){
                cntzero--;
            }
            else if(str[k]=='1'){
                result=min(result,cnt+cntzero);
                cnt+=1;
            }
        }
        if(str[0]=='1'){
            cout<<temp<<endl;
        }
        else{
            cout<<min(result,cnt)<<endl;
        }
    }
    return 0;
}
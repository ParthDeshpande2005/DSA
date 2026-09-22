#include<bits/stdc++.h> 
using namespace std;


int dp(string &st,int i,int len,vector<int> &memo){
    if(i==len){
        return 0;
    }

    if(memo[i]!=-1){
        return memo[i];
    }

    //make one->
    int one=0;
    for(int j=i;j<len;j++){
        if(st[j]=='0'){
            one++;
        }
    }

    //make zero->
    int zero=dp(st,i+1,len,memo);
    if(st[i]=='1'){
        zero+=1;
    }

    return memo[i]=min(one,zero);
}
int main(){
    int n;
    cin>>n;
    for(int k=0;k<n;k++){
        int len;
        cin>>len;
        string cur;
        cin>>cur;
        //if first is one we need to convert all to 1.
        if(cur[0]=='1'){
            int count=0;
            for(int j=0;j<len;j++){
                if(cur[j]=='0'){
                    count++;
                }
            }
            cout<<count<<endl;
        }
        else if(cur[0]=='0'){
            int i=0;
            while(i<len && cur[i]!='1'){
                i++;
            }
            if(i==len){
                cout<<0<<endl;
            }
            else{
                //dp
                vector<int> memo(len,-1);
                int result=dp(cur,i,len,memo);
                cout<<result<<endl;
            }
        }
    }
    return 0;
}